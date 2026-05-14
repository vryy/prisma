//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Riccardo Rossi
//

#if !defined(KRATOS_FIND_NODAL_NEIGHBOURS_PROCESS_H_INCLUDED )
#define  KRATOS_FIND_NODAL_NEIGHBOURS_PROCESS_H_INCLUDED

// System includes
#include <string>
#include <iostream>

// External includes

// Project includes
#include "includes/define.h"
#include "processes/process.h"
#include "includes/node.h"
#include "includes/element.h"
#include "includes/model_part.h"

namespace Kratos
{

///@name Kratos Globals
///@{

///@}
///@name Type Definitions
///@{

///@}
///@name  Enum's
///@{

///@}
///@name  Functions
///@{

///@}
///@name Kratos Classes
///@{

/**
 * @class FindNodalNeighboursProcess
 * @brief This process looks for neighbours of the node in a finite element mesh.
 *          This fill the NEIGHBOUR_NODES value field of a node
 */
class KRATOS_API(KRATOS_CORE) FindNodalNeighboursProcess
    : public Process
{
public:
    ///@name Type Definitions
    ///@{

    /// Pointer definition of FindNodalNeighboursProcess
    KRATOS_CLASS_POINTER_DEFINITION(FindNodalNeighboursProcess);

    typedef ModelPart::NodesContainerType NodesContainerType;
    typedef ModelPart::ElementsContainerType ElementsContainerType;

    ///@}
    ///@name Life Cycle
    ///@{

    /**
     * @brief Default constructor
     * @param rModelPart The modelpart to be processed
     * @param AverageElements Expected number of neighbour elements per node.
     * @param AverageNodes Expected number of neighbour Nodes
    */
    FindNodalNeighboursProcess(ModelPart& model_part, unsigned int avg_elems = 10, unsigned int avg_nodes = 10)
        : mr_model_part(model_part)
    {
        mavg_elems = avg_elems;
        mavg_nodes = avg_nodes;
    }

    /// Destructor.
    ~FindNodalNeighboursProcess() override
    {
    }


    ///@}
    ///@name Operators
    ///@{


    ///@}
    ///@name Operations
    ///@{

    /**
     * @brief This method esxecutes the neighbour search
     */
    void Execute() override
    {
        NodesContainerType& rNodes = mr_model_part.Nodes();
        ElementsContainerType& rElems = mr_model_part.Elements();

        //first of all the neighbour nodes and elements array are initialized to the guessed size
        //and empties the old entries
        for(NodesContainerType::iterator in = rNodes.begin(); in != rNodes.end(); in++)
        {
            (in->GetValue(NEIGHBOUR_NODES)).reserve(mavg_nodes);
            WeakPointerVector<Node<3> >& rN = in->GetValue(NEIGHBOUR_NODES);
            rN.erase(rN.begin(),rN.end() );

            (in->GetValue(NEIGHBOUR_ELEMENTS)).reserve(mavg_elems);
            WeakPointerVector<Element >& rE = in->GetValue(NEIGHBOUR_ELEMENTS);
            rE.erase(rE.begin(),rE.end() );
        }

        //add the neighbour elements to all the nodes in the mesh
        for(ElementsContainerType::iterator ie = rElems.begin(); ie!=rElems.end(); ie++)
        {
            Element::GeometryType& pGeom = ie->GetGeometry();
            for(unsigned int i = 0; i < pGeom.size(); i++)
            {
                //KRATOS_WATCH( pGeom[i] );
                (pGeom[i].GetValue(NEIGHBOUR_ELEMENTS)).push_back( Element::WeakPointer( *(ie.base()) ) );
                //KRATOS_WATCH( (pGeom[i].GetValue(NEIGHBOUR_ELEMENTS)).size() );
            }
        }

        //adding the neighbouring nodes
        for(NodesContainerType::iterator in = rNodes.begin(); in!=rNodes.end(); in++)
        {
            WeakPointerVector<Element >& rE = in->GetValue(NEIGHBOUR_ELEMENTS);

            for(unsigned int ie = 0; ie < rE.size(); ie++)
            {
                Element::GeometryType& pGeom = rE[ie].GetGeometry();
                for(unsigned int i = 0; i < pGeom.size(); i++)
                {
                    if(pGeom[i].Id() != in->Id() )
                    {
                        Element::NodeType::WeakPointer temp = pGeom(i);
                        AddUniqueWeakPointer< Node<3> >(in->GetValue(NEIGHBOUR_NODES), temp);
                    }
                }
            }
        }
    }

    /**
     * @brief This method clears the neighbours found
     */
    void ClearNeighbours()
    {
        NodesContainerType& rNodes = mr_model_part.Nodes();
        for(NodesContainerType::iterator in = rNodes.begin(); in!=rNodes.end(); in++)
        {
            WeakPointerVector<Element >& rE = in->GetValue(NEIGHBOUR_ELEMENTS);
            rE.erase(rE.begin(),rE.end());

            WeakPointerVector<Node<3> >& rN = in->GetValue(NEIGHBOUR_NODES);
            rN.erase(rN.begin(),rN.end() );
        }
    }

    ///@}
    ///@name Access
    ///@{


    ///@}
    ///@name Inquiry
    ///@{


    ///@}
    ///@name Input and output
    ///@{

    /// Turn back information as a string.
    std::string Info() const override
    {
        return "FindNodalNeighboursProcess";
    }

    ///@}
    ///@name Friends
    ///@{


    ///@}

protected:
    ///@name Protected static Member Variables
    ///@{


    ///@}
    ///@name Protected member Variables
    ///@{


    ///@}
    ///@name Protected Operators
    ///@{


    ///@}
    ///@name Protected Operations
    ///@{


    ///@}
    ///@name Protected  Access
    ///@{


    ///@}
    ///@name Protected Inquiry
    ///@{


    ///@}
    ///@name Protected LifeCycle
    ///@{


    ///@}

private:
    ///@name Static Member Variables
    ///@{


    ///@}
    ///@name Member Variables
    ///@{
    ModelPart& mr_model_part;
    unsigned int mavg_elems;
    unsigned int mavg_nodes;


    ///@}
    ///@name Private Operators
    ///@{

    //******************************************************************************************
    //******************************************************************************************
    template< class TDataType > void  AddUniqueWeakPointer
    (WeakPointerVector< TDataType >& v, const typename TDataType::WeakPointer candidate)
    {
        typename WeakPointerVector< TDataType >::iterator i = v.begin();
        typename WeakPointerVector< TDataType >::iterator endit = v.end();
        while ( i != endit && (i)->Id() != (candidate.lock())->Id())
        {
            i++;
        }
        if( i == endit )
        {
            v.push_back(candidate);
        }

    }

    ///@}
    ///@name Private Operations
    ///@{


    ///@}
    ///@name Private  Access
    ///@{


    ///@}
    ///@name Private Inquiry
    ///@{


    ///@}
    ///@name Un accessible methods
    ///@{

    /// Assignment operator.
    FindNodalNeighboursProcess& operator=(FindNodalNeighboursProcess const& rOther);

    /// Copy constructor.
    //FindNodalNeighboursProcess(FindNodalNeighboursProcess const& rOther);


    ///@}

}; // Class FindNodalNeighboursProcess

///@}

///@name Type Definitions
///@{


///@}
///@name Input and output
///@{


///@}

}  // namespace Kratos.

#endif // KRATOS_FIND_NODAL_NEIGHBOURS_PROCESS_H_INCLUDED  defined
