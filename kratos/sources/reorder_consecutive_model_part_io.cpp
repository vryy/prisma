//    |  /           |
//    ' /   __| _` | __|  _ \   __|
//    . \  |   (   | |   (   |\__ `
//   _|\_\_|  \__,_|\__|\___/ ____/
//                   Multi-Physics
//
//  License:         BSD License
//                   Kratos default license: kratos/license.txt
//
//  Main authors:    Pooyan Dadvand
//

// Project includes
#include "includes/reorder_consecutive_model_part_io.h"

namespace Kratos
{
    template<class TModelPartType>
    ReorderConsecutiveModelPartIO<TModelPartType>::ReorderConsecutiveModelPartIO(std::string const& Filename, const Flags Options )
        : BaseType(Filename, Options),
        mNumberOfNodes(0),
        mNumberOfElements(0),
        mNumberOfConditions(0),
        mNodeIdMap(),
        mElementIdMap(),
        mConditionIdMap()
    {
    }

    template<class TModelPartType>
    ReorderConsecutiveModelPartIO<TModelPartType>::~ReorderConsecutiveModelPartIO()
    {}

    template<class TModelPartType>
    typename ReorderConsecutiveModelPartIO<TModelPartType>::SizeType ReorderConsecutiveModelPartIO<TModelPartType>::ReorderedNodeId(SizeType NodeId)
    {
        typename IdMapType::iterator i = mNodeIdMap.find(NodeId);
        if(i != mNodeIdMap.end())
            return i->second;

        mNodeIdMap.insert(typename IdMapType::value_type(NodeId, ++mNumberOfNodes));
        return mNumberOfNodes;
    }

    template<class TModelPartType>
    typename ReorderConsecutiveModelPartIO<TModelPartType>::SizeType ReorderConsecutiveModelPartIO<TModelPartType>::ReorderedElementId(SizeType ElementId)
    {
        typename IdMapType::iterator i = mElementIdMap.find(ElementId);
        if(i != mElementIdMap.end())
            return i->second;

        mElementIdMap.insert(typename IdMapType::value_type(ElementId, ++mNumberOfElements));
        return mNumberOfElements;
    }

    template<class TModelPartType>
    typename ReorderConsecutiveModelPartIO<TModelPartType>::SizeType ReorderConsecutiveModelPartIO<TModelPartType>::ReorderedConditionId(SizeType ConditionId)
    {
        typename IdMapType::iterator i = mConditionIdMap.find(ConditionId);
        if(i != mConditionIdMap.end())
            return i->second;

        mConditionIdMap.insert(typename IdMapType::value_type(ConditionId, ++mNumberOfConditions));
        return mNumberOfConditions;
    }

    /// template class instantiation
    template class ReorderConsecutiveModelPartIO<ModelPart>;
    template class ReorderConsecutiveModelPartIO<ComplexModelPart>;
    template class ReorderConsecutiveModelPartIO<GComplexModelPart>;

}  // namespace Kratos.
