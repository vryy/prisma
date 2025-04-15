//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 1 Oct 2015 $
//   Revision:            $Revision: 1.0 $
//
//


#if !defined(KRATOS_BOUNDING_VOLUME_TREE_H_INCLUDED )
#define  KRATOS_BOUNDING_VOLUME_TREE_H_INCLUDED



// System includes
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>


// External includes


// Project includes
#include "includes/define.h"
#include "includes/variables.h"
#include "includes/node.h"
#include "includes/model_part.h"
#include "geometries/point.h"
#include "geometries/geometry.h"


namespace Kratos
{

/// Class Description:
/// +   This abstract class represents a k-discrete oriented polytope (k-DOP) in 3D
/// +   k-DOP is a bounding volume concept, that allows to wrap a geometry in a convex volume
class KRATOS_API(KRATOS_CORE) kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(kDOP);

    typedef Node<3> NodeType;
    typedef Geometry<NodeType> GeometryType;
    typedef NodeType::PointType PointType;

    kDOP() {this->Initialize();}

    virtual ~kDOP() {}

    /// Return the number of directions of the k-DOP
    virtual std::size_t NumberOfDirections() const
    {
        return 1;
    }

    /// Initialize the bounding volume to initial state
    void Initialize()
    {
        mMinValues.resize(this->NumberOfDirections());
        mMaxValues.resize(this->NumberOfDirections());
        std::fill(mMinValues.begin(), mMinValues.end(), static_cast<double>(INT_MAX));
        std::fill(mMaxValues.begin(), mMaxValues.end(), -static_cast<double>(INT_MAX));
    }

    /// Compute the normal coordinates of a point
    std::vector<double> NormalCoordinates(const PointType& r_point) const
    {
        std::vector<double> coords(this->NumberOfDirections());
        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
            coords[i] = NormalCoordinate(i, r_point[0], r_point[1], r_point[2]);
        return coords;
    }

    /// Check if the point is inside the bounding volume
    /// tolerance parameter is to account for proximity
    bool IsInside(const PointType& r_point, const double tolerance) const
    {
        bool is_inside = true;
        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
        {
            double v = NormalCoordinate(i, r_point[0], r_point[1], r_point[2]);
            is_inside &= ((v >= mMinValues[i] - tolerance) && (v <= mMaxValues[i] + tolerance));
            if(!is_inside)
                break;
        }
        return is_inside;
    }

    /// Test if this bounding volume overlap or no-overlaping with another one
    /// The meaning of return value:
    ///     +   0: the two BVs are not overlapping within the tolerance, which mean this condition is satisfied in at least one direction: (this.max <= other.min - tol) or (this.min >= other.max + tol)
    ///     +   1: the two BVs are overlapping, which means in all direction, this condition is satisfied: (this.max >= other.min + tol) or (this.min <= other.max - tol)
    ///     +   2: the two BVs are in tangent to each other (only enabled if test_tangent == true)
    int TestOverlapped(const kDOP& rOther, const double tolerance, const bool test_tangent = true) const
    {
        if(this->NumberOfDirections() != rOther.NumberOfDirections())
            return false;

        int mode = 1;
        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
        {
            if( (mMaxValues[i] <= rOther.MinValues()[i] - tolerance) || (mMinValues[i] >= rOther.MaxValues()[i] + tolerance) )
            {
                mode = 0;
                break;
            }
        }

        if(mode != 0 && test_tangent)
        {
            for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
            {
                if( !(mMaxValues[i] >= rOther.MinValues()[i] + tolerance) && !(mMinValues[i] <= rOther.MaxValues()[i] - tolerance) )
                {
                    mode = 2;
                    break;
                }
            }
        }

        return mode;
    }

    /// Add a point to the DOP /// This is mainly used for debugging
    void InsertPoint(const double rX, const double rY, const double rZ)
    {
        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
        {
            double v = NormalCoordinate(i, rX, rY, rZ);
            if(v < mMinValues[i])
                mMinValues[i] = v;
            if(v > mMaxValues[i])
                mMaxValues[i] = v;
        }
    }

    /// Add a geometry (from an element/a condition) to the k-DOP
    template<int TFrame>
    void InsertGeometry(const GeometryType& rGeometry)
    {
        for(std::size_t i = 0; i < rGeometry.size(); ++i)
        {
            if constexpr(TFrame == 1)
            {
                this->InsertPoint(rGeometry[i].X0() + rGeometry[i].GetSolutionStepValue(DISPLACEMENT_X),
                                  rGeometry[i].Y0() + rGeometry[i].GetSolutionStepValue(DISPLACEMENT_Y),
                                  rGeometry[i].Z0() + rGeometry[i].GetSolutionStepValue(DISPLACEMENT_Z));
//                this->InsertPoint(rGeometry[i].X(), rGeometry[i].Y(), rGeometry[i].Z());
            }
            else if constexpr(TFrame == 0)
            {
                this->InsertPoint(rGeometry[i].X0(), rGeometry[i].Y0(), rGeometry[i].Z0());
            }
        }
    }

    /// Set the bounding volume by summing up two BVs. It will re-initialize all data of this kDOP
    void SetVolume(const kDOP& rBV1, const kDOP& rBV2)
    {
        if( (rBV1.GetType() != this->GetType()) || (rBV2.GetType() != this->GetType()) )
            KRATOS_ERROR << "The BV type is incompatible";

        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
        {
            mMinValues[i] = std::min(rBV1.MinValues()[i], rBV2.MinValues()[i]);
            mMaxValues[i] = std::max(rBV1.MaxValues()[i], rBV2.MaxValues()[i]);
        }
    }

    /// Set the bounding volume by intersecting two BVs. It will re-initialize all data of this kDOP
    bool SetVolumeIntersection(const kDOP& rBV1, const kDOP& rBV2, const double tolerance)
    {
        int test = rBV1.TestOverlapped(rBV2, tolerance, true);
        if(test == 1)
        {
            for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
            {
                mMinValues[i] = std::max(rBV1.MinValues()[i], rBV2.MinValues()[i]);
                mMaxValues[i] = std::min(rBV1.MaxValues()[i], rBV2.MaxValues()[i]);
            }
            return true;
        }
        return false;
    }

    /// Get the respective minimum values and maximum values of this bounding volume
    const std::vector<double>& MinValues() const {return mMinValues;}
    const std::vector<double>& MaxValues() const {return mMaxValues;}

    /// Get the longest axis
    std::size_t GetLongestAxis() const
    {
        std::size_t longest_axis = 0;
        double length = 0.0;
        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
        {
            double tmp = fabs(mMaxValues[i] - mMinValues[i]);
            if(tmp > length)
            {
                longest_axis = i;
                length = tmp;
            }
        }
        return longest_axis;
    }

    /// Get the i'th-direction
    const double (&Direction(const std::size_t& i) const)[3] {return Direction()[i];}

    /// Get the i'th-direction Normalized
    const double (&DirectionNormalized(const std::size_t& i) const)[3] {return DirectionNormalized()[i];}

    /// Get the type of this k-DOP
    std::size_t GetType() const {return 2 * NumberOfDirections();}

    /// Get the vertices of the bounding box by using vertex enumeration algorithm
    /// Introduction to vertex enumeration: https://en.wikipedia.org/wiki/Vertex_enumeration_problem
//    void GetVertices(std::vector<std::vector<double> >& rCorners) const
//    {
//        // TODO
//    }

    /// Export the inequalities (minimal H-representation) representing the polytopes. In general, any polyhedron/polytope can be represented by set of inequality equations: Mx <= b
    /// This can i.e be used to export data for other vertex enumeration package, to obtain the V-representation of the polytope, e.g. cddlib/lrs
    /// cddlib: https://www.inf.ethz.ch/personal/fukudak/cdd_home/index.html
    /// lrs: http://cgm.cs.mcgill.ca/~avis/C/lrs.html
    void GetInequalities(Matrix& rM, Vector& rB) const
    {
        // resize as needed
        if(rM.size1() != 2 * NumberOfDirections() || rM.size2() != 3)
            rM.resize(2 * NumberOfDirections(), 3);

        if(rB.size() != 2 * NumberOfDirections())
            rB.resize(2 * NumberOfDirections());

        for(std::size_t i = 0; i < NumberOfDirections(); ++i)
        {
            rM(2 * i, 0) = Direction()[i][0];
            rM(2 * i, 1) = Direction()[i][1];
            rM(2 * i, 2) = Direction()[i][2];
            rB(2 * i) = mMaxValues[i];

            rM(2 * i + 1, 0) = -Direction()[i][0];
            rM(2 * i + 1, 1) = -Direction()[i][1];
            rM(2 * i + 1, 2) = -Direction()[i][2];
            rB(2 * i + 1) = -mMinValues[i];
        }
    }

    void PrintInfo(std::ostream& rOStream) const
    {
        rOStream << this->GetType() << "-DOP:";
        for(std::size_t i = 0; i < this->NumberOfDirections(); ++i)
            rOStream << " (" << mMinValues[i] << ", " << mMaxValues[i] << ")";
    }

private:
    std::vector<double> mMinValues;
    std::vector<double> mMaxValues;
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    virtual const double (*Direction() const)[3];
    virtual const double (*DirectionNormalized() const)[3];
    double NormalCoordinate(int i, const double rX, const double rY, const double rZ) const
    {
        return rX * DirectionNormalized()[i][0] + rY * DirectionNormalized()[i][1] + rZ * DirectionNormalized()[i][2];
    }
};

/// output stream function
inline std::ostream& operator <<(std::ostream& rOStream, const kDOP& rThis)
{
    rThis.PrintInfo(rOStream);
    return rOStream;
}

class KRATOS_API(KRATOS_CORE) _6DOP : public kDOP // AABB
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_6DOP);
    _6DOP() : kDOP() {this->Initialize();}
    ~_6DOP() override {}
    std::size_t NumberOfDirections() const override {return 3;}

private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};

class KRATOS_API(KRATOS_CORE) _8DOP : public kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_8DOP);
    _8DOP() : kDOP() {this->Initialize();}
    ~_8DOP() override {}
    std::size_t NumberOfDirections() const override {return 4;}
private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};

class KRATOS_API(KRATOS_CORE) _12DOP : public kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_12DOP);
    _12DOP() : kDOP() {this->Initialize();}
    ~_12DOP() override {}
    std::size_t NumberOfDirections() const override {return 6;}
private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};

class KRATOS_API(KRATOS_CORE) _14DOP : public kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_14DOP);
    _14DOP() : kDOP() {this->Initialize();}
    ~_14DOP() override {}
    std::size_t NumberOfDirections() const override {return 7;}
private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};

class KRATOS_API(KRATOS_CORE) _18DOP : public kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_18DOP);
    _18DOP() : kDOP() {this->Initialize();}
    ~_18DOP() override {}
    std::size_t NumberOfDirections() const override {return 9;}
private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};

class KRATOS_API(KRATOS_CORE) _20DOP : public kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_20DOP);
    _20DOP() : kDOP() {this->Initialize();}
    ~_20DOP() override {}
    std::size_t NumberOfDirections() const override {return 10;}
private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};

class KRATOS_API(KRATOS_CORE) _26DOP : public kDOP
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(_26DOP);
    _26DOP() : kDOP() {this->Initialize();}
    ~_26DOP() override {}
    std::size_t NumberOfDirections() const override {return 13;}
private:
    static const double msDirection[][3];
    static const double msDirectionNormalized[][3];
    const double (*Direction() const)[3] override;
    const double (*DirectionNormalized() const)[3] override;
};


/// Class Description:
/// +   Abstract class for the spliting of nodes used for constructing the bounding volume tree in top-down approach
/// +   The derivative of this class must implement the sub-routine Partition, where the set of elemental Ids is splitted in 2 parts.
template<int TFrame = 1, class ContainerType = ModelPart::ConditionsContainerType>
class KRATOS_API(KRATOS_CORE) BoundingVolumePartitioner
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(BoundingVolumePartitioner);
    BoundingVolumePartitioner() {}
    virtual ~BoundingVolumePartitioner() {}

    typedef Node<3> NodeType;
    typedef Geometry<NodeType> GeometryType;
    typedef NodeType::PointType PointType;

    virtual void Partition(const ContainerType& rAllConditions,
                           const kDOP& rBoundingVolume,
                           ContainerType& rOutputSet1,
                           ContainerType& rOutputSet2) const
    {
        KRATOS_ERROR << "Calling base function";
    }

    void ComputeCentroid(GeometryType& rGeometry, double C[3]) const
    {
        C[0] = 0.0;
        C[1] = 0.0;
        C[2] = 0.0;
        unsigned int n = rGeometry.size();

        if constexpr (TFrame == 0)
        {
            for(std::size_t i = 0; i < n; ++i)
            {
                C[0] += rGeometry[i].X0();
                C[1] += rGeometry[i].Y0();
                C[2] += rGeometry[i].Z0();
            }
        }
        else if constexpr (TFrame == 1)
        {
            for(std::size_t i = 0; i < n; ++i)
            {
                C[0] += rGeometry[i].X0() + rGeometry[i].GetSolutionStepValue(DISPLACEMENT_X);
                C[1] += rGeometry[i].Y0() + rGeometry[i].GetSolutionStepValue(DISPLACEMENT_Y);
                C[2] += rGeometry[i].Z0() + rGeometry[i].GetSolutionStepValue(DISPLACEMENT_Z);
            }
        }

        C[0] /= n;
        C[1] /= n;
        C[2] /= n;
    }
};


template<int TFrame = 1, class ContainerType = ModelPart::ConditionsContainerType>
class KRATOS_API(KRATOS_CORE) SimpleBoundingVolumePartitioner : public BoundingVolumePartitioner<TFrame, ContainerType>
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(SimpleBoundingVolumePartitioner);
    SimpleBoundingVolumePartitioner() {}
    ~SimpleBoundingVolumePartitioner() override {}

    /// REF: https://github.com/brandonpelfrey/Fast-BVH
    void Partition(const ContainerType& rAllConditions,
                   const kDOP& rBoundingVolume,
                   ContainerType& rOutputSet1,
                   ContainerType& rOutputSet2) const final
    {
        // for simplest case, if there is only one segment, then output 1 is set straightforward
        if(rAllConditions.size() == 1)
        {
            for(typename ContainerType::ptr_const_iterator it = rAllConditions.ptr_begin(); it != rAllConditions.ptr_end(); ++it)
                rOutputSet1.push_back(*it);
        }

        // for another simple case, if there are only 2 segments then divide by half and quit
        if(rAllConditions.size() == 2)
        {
            int cnt = 0;
            for(typename ContainerType::ptr_const_iterator it = rAllConditions.ptr_begin(); it != rAllConditions.ptr_end(); ++it)
            {
                if(cnt == 0)
                    rOutputSet1.push_back(*it);
                else
                    rOutputSet2.push_back(*it);
                ++cnt;
            }
            return;
        }

        // extract the longest axis of the bounding volume
        std::size_t longest_axis = rBoundingVolume.GetLongestAxis();
        const double* check_dir;
        std::size_t check_axis = longest_axis;
        std::size_t ncheck = 0;

        do
        {
            check_dir = rBoundingVolume.Direction(check_axis);

            // compute the centroid of the geometries underlying bounding volume
            double C[3];
            double Median[3];
            Median[0] = 0.0;
            Median[1] = 0.0;
            Median[2] = 0.0;
            for(typename ContainerType::ptr_const_iterator it = rAllConditions.ptr_begin(); it != rAllConditions.ptr_end(); ++it)
            {
                this->ComputeCentroid((*it)->GetGeometry(), C);
                Median[0] += C[0];
                Median[1] += C[1];
                Median[2] += C[2];
            }
            Median[0] /= rAllConditions.size();
            Median[1] /= rAllConditions.size();
            Median[2] /= rAllConditions.size();

            // divide each geometry in the InputSet to each of OutputSet
            for(typename ContainerType::ptr_const_iterator it = rAllConditions.ptr_begin(); it != rAllConditions.ptr_end(); ++it)
            {
                this->ComputeCentroid((*it)->GetGeometry(), C);
                double v = 0.0;
                for(std::size_t j = 0; j < 3; ++j)
                    v += (C[j] - Median[j]) * check_dir[j];
                if(v < 0)
                    rOutputSet1.push_back(*it);
                else
                    rOutputSet2.push_back(*it);
            }

            // make a size check
            if(rOutputSet1.size() == 0 || rOutputSet2.size() == 0)
            // that can fail if the medians of the cell are aligned on the perpendicular axis to the checking axis
            {
                ++ncheck;
                // take a new axis and perform partitioning again
                ++check_axis;
                if (check_axis >= rBoundingVolume.NumberOfDirections())
                    check_axis = 0;
                rOutputSet1.clear();
                rOutputSet2.clear();
            }
            else
                return; // return on success
        } while (ncheck < rBoundingVolume.NumberOfDirections());

        KRATOS_ERROR << "The simple partitioning strategy does not work. That can't happen but if it does, the medians are possibly coincident.";
    }
};


template<int TFrame = 1, class ContainerType = ModelPart::ConditionsContainerType>
class KRATOS_API(KRATOS_CORE) LineRegressionVolumePartitioner : public BoundingVolumePartitioner<TFrame, ContainerType>
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(LineRegressionVolumePartitioner);
    LineRegressionVolumePartitioner() {}
    ~LineRegressionVolumePartitioner() override {}

    void Partition(const ContainerType& rAllConditions,
                   const kDOP& rBoundingVolume,
                   ContainerType& rOutputSet1,
                   ContainerType& rOutputSet2) const final
    {
        // firstly extract all the nodes of the providing geometry
        std::set<std::size_t> NodeIds;
        for(typename ContainerType::ptr_const_iterator it = rAllConditions.ptr_begin(); it != rAllConditions.ptr_end(); ++it)
            for(std::size_t j = 0; j < (*it)->GetGeometry().size(); ++j)
                NodeIds.insert((*it)->GetGeometry()[j].Id());

        // build the 3D regression line of the point set
        // Here I used a simple approach:
        //  +   I perform linear fit for (x,z) data, then I got the surface perpendicular to Oxz. Similarly, I fit (y,z) data to get the surface perpendicular to Oyz. Intersection of 2 surfaces gives me an approximation of best line fit of my 3D data
        //  +   Theoretically, it's best to use PCA (Principal Component Analysis) to reduce the 3D cloud data to a line. But it would be an overkill due to SVD.
        //  REF: http://stackoverflow.com/questions/24747643/3d-linear-regression
        //       http://stackoverflow.com/questions/2298390/fitting-a-line-in-3d
        // TODO
    }
};


/// Class Description:
/// +   Bounding volume tree is the spatial container for fast collision detection. It is mainly used as the contact search algorithm.
/// +
/// +   This class requires following components:
/// +   -
///
///
/// REFERENCE:
/// +   Yang & Laursen, A contact searching algorithm including bounding volume trees applied to finite sliding mortar formulations
/// +   Klosowski et al, Efficient collision detection using bounding volume hierarchies of k-DOPs
template<int TFrame = 1, class ContainerType = ModelPart::ConditionsContainerType>
class KRATOS_API(KRATOS_CORE) BoundingVolumeTree
{
public:
    KRATOS_CLASS_POINTER_DEFINITION(BoundingVolumeTree);

    typedef kDOP::PointType PointType;

    BoundingVolumeTree(const int type)
    {
        if(type == 6)
            mpBV = kDOP::Pointer(new _6DOP());
        else if(type == 8)
            mpBV = kDOP::Pointer(new _8DOP());
        else if(type == 12)
            mpBV = kDOP::Pointer(new _12DOP());
        else if(type == 14)
            mpBV = kDOP::Pointer(new _14DOP());
        else if(type == 18)
            mpBV = kDOP::Pointer(new _18DOP());
        else if(type == 20)
            mpBV = kDOP::Pointer(new _20DOP());
        else if(type == 26)
            mpBV = kDOP::Pointer(new _26DOP());
        else
            KRATOS_ERROR << "Invalid k-DOP type " << type;
    }

    virtual ~BoundingVolumeTree()
    {}

    void BuildTreeTopDown(const ContainerType& rAllConditions, const BoundingVolumePartitioner<TFrame, ContainerType>& rPartitioner)
    {
        mGeometryIds.clear();
        mpBV->Initialize();
        this->AddGeometryFrom(rAllConditions);

        if(rAllConditions.size() < 2)
            return;

        ContainerType ChildSet1;
        ContainerType ChildSet2;
        rPartitioner.Partition(rAllConditions, *mpBV, ChildSet1, ChildSet2);

        // size check
        if( (ChildSet1.size() == 0 && ChildSet2.size() > 0)
         || (ChildSet1.size() > 0 && ChildSet2.size() == 0) )
            KRATOS_ERROR << "There is something wrong with the partitioning. The size of the two sub-sets must be non-zero concurrently";

        if(ChildSet1.size() > 0)
        {
            mpLeft = BoundingVolumeTree::Pointer(new BoundingVolumeTree(mpBV->GetType()));
            mpLeft->BuildTreeTopDown(ChildSet1, rPartitioner);
        }
        if(ChildSet2.size() > 0)
        {
            mpRight = BoundingVolumeTree::Pointer(new BoundingVolumeTree(mpBV->GetType()));
            mpRight->BuildTreeTopDown(ChildSet2, rPartitioner);
        }
    }


    void UpdateTree(const ContainerType& rAllConditions)
    {
        if((mpLeft != NULL) && (mpRight != NULL))
        {
            mpLeft->UpdateTree(rAllConditions);
            mpRight->UpdateTree(rAllConditions);
            mpBV->SetVolume(mpLeft->GetBoundingVolume(), mpRight->GetBoundingVolume());
        }
        else
        {
            mpBV->Initialize();
            for(std::set<std::size_t>::iterator it = mGeometryIds.begin(); it != mGeometryIds.end(); ++it)
            {
                auto it2 = rAllConditions.find(*it);
                mpBV->InsertGeometry<TFrame>(it2->GetGeometry());
            }
        }
    }

    void AddGeometryFrom(const ContainerType& rAllConditions)
    {
        for(typename ContainerType::ptr_const_iterator it = rAllConditions.ptr_begin(); it != rAllConditions.ptr_end(); ++it)
        {
            mpBV->InsertGeometry<TFrame>((*it)->GetGeometry());
            mGeometryIds.insert((*it)->Id());
        }
    }

    template<typename TGeometryContainerType>
    void GetContainingGeometries(TGeometryContainerType& rGeometryIds, const PointType& r_point, const double tolerance) const
    {
        if(mGeometryIds.size() == 0)
            return;

        if(this->IsLeaf())
        {
            if (mpBV->IsInside(r_point, tolerance))
                rGeometryIds.insert(mGeometryIds.begin(), mGeometryIds.end());
        }
        else
        {
            if(mpLeft != NULL)
                mpLeft->GetContainingGeometries(rGeometryIds, r_point, tolerance);
            if(mpRight != NULL)
                mpRight->GetContainingGeometries(rGeometryIds, r_point, tolerance);
        }
    }

    const kDOP& GetBoundingVolume() const {return *mpBV;}

    bool IsLeaf() const {return (mpLeft == NULL) && (mpRight == NULL);}

    std::size_t Depth() const
    {
        std::size_t depth = 0;
        if(mpLeft != NULL)
            depth = mpLeft->Depth();
        if(mpRight != NULL)
            depth = std::max(depth, mpRight->Depth());
        return depth+1;
    }

    bool CheckValidity() const
    {
        if(mGeometryIds.size() == 0)
            return true;

        if(this->IsLeaf() && mGeometryIds.size() != 1)
            return false;
        else
        {
            bool valid = true;
            if(mpLeft != NULL)
                valid = valid && mpLeft->CheckValidity();
            if(mpRight != NULL)
                valid = valid && mpRight->CheckValidity();
            return valid;
        }
    }

    std::size_t GetFirstGeometryId() const
    {
        return *(mGeometryIds.begin());
    }

    const BoundingVolumeTree& GetLeftTree() const {return *mpLeft;}
    BoundingVolumeTree::Pointer pGetLeftTree() const {return mpLeft;}

    const BoundingVolumeTree& GetRightTree() const {return *mpRight;}
    BoundingVolumeTree::Pointer pGetRightTree() const {return mpRight;}

    void Print(std::ostream& rOStream, unsigned int level) const
    {
        mpBV->PrintInfo(rOStream);
        rOStream << ", Geometry Id:";
        for(std::set<std::size_t>::iterator it = mGeometryIds.begin(); it != mGeometryIds.end(); ++it)
            rOStream << " " << *it;
        rOStream << std::endl;
        if(mpLeft != NULL)
        {
            for(unsigned int i = 0; i < level; ++i)
                rOStream << "|  ";
            rOStream << "'->Left branch:";
            mpLeft->Print(rOStream, level + 1);
        }
        if(mpRight != NULL)
        {
            for(unsigned int i = 0; i < level; ++i)
                rOStream << "|  ";
            rOStream << "'->Right branch:";
            mpRight->Print(rOStream, level + 1);
        }
    }

private:
    kDOP::Pointer mpBV;

    BoundingVolumeTree::Pointer mpLeft;
    BoundingVolumeTree::Pointer mpRight;

    std::set<std::size_t> mGeometryIds; // this container is to keep the id of the element/condition added to the BVH to perform the update later on
};

}  // namespace Kratos.

#endif // KRATOS_BOUNDING_VOLUME_TREE_H_INCLUDED  defined
