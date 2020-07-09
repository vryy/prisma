//
//   Project Name:        Kratos
//   Last Modified by:    $Author: hbui $
//   Date:                $Date: 1 Oct 2015 $
//   Revision:            $Revision: 1.0 $
//
//

#include "spatial_containers/bounding_volume_tree.h"

namespace Kratos
{

const double kDOP::msDirection[][3] = {{1, 1, 1}};
const double _6DOP::msDirection[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
const double _8DOP::msDirection[][3] = {{1, 1, 1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, -1}};
const double _12DOP::msDirection[][3] = {{1, 1, 0}, {1, -1, 0}, {1, 0, 1}, {1, 0, -1}, {0, 1, 1}, {0, 1, -1}};
const double _14DOP::msDirection[][3] = {  {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                           {1, 1, 1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, -1} };
const double _18DOP::msDirection[][3] = {  {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                           {1, 1, 0}, {1, -1, 0}, {1, 0, 1}, {1, 0, -1}, {0, 1, 1}, {0, 1, -1} };
const double _20DOP::msDirection[][3] = {  {1, 1, 1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, -1},
                                           {1, 1, 0}, {1, -1, 0}, {1, 0, 1}, {1, 0, -1}, {0, 1, 1}, {0, 1, -1} };
const double _26DOP::msDirection[][3] = {  {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                           {1, 1, 1}, {-1, 1, 1}, {1, -1, 1}, {1, 1, -1},
                                           {1, 1, 0}, {1, -1, 0}, {1, 0, 1}, {1, 0, -1}, {0, 1, 1}, {0, 1, -1} };

const double kDOP::msDirectionNormalized[][3] = {{0.577350269189, 0.577350269189, 0.577350269189}};
const double _6DOP::msDirectionNormalized[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
const double _8DOP::msDirectionNormalized[][3] = {{0.577350269189, 0.577350269189, 0.577350269189}, {-0.577350269189, 0.577350269189, 0.577350269189}, {0.577350269189, -0.577350269189, 0.577350269189}, {0.577350269189, 0.577350269189, -0.577350269189}};
const double _12DOP::msDirectionNormalized[][3] = {{0.707106781188, 0.707106781188, 0}, {0.707106781188, -0.707106781188, 0}, {0.707106781188, 0, 0.707106781188}, {0.707106781188, 0, -0.707106781188}, {0, 0.707106781188, 0.707106781188}, {0, 0.707106781188, -0.707106781188}};
const double _14DOP::msDirectionNormalized[][3] = {  {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                          {0.577350269189, 0.577350269189, 0.577350269189}, {-0.577350269189, 0.577350269189, 0.577350269189}, {0.577350269189, -0.577350269189, 0.577350269189}, {0.577350269189, 0.577350269189, -0.577350269189} };
const double _18DOP::msDirectionNormalized[][3] = {  {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                          {0.707106781188, 0.707106781188, 0}, {0.707106781188, -0.707106781188, 0}, {0.707106781188, 0, 0.707106781188}, {0.707106781188, 0, -0.707106781188}, {0, 0.707106781188, 0.707106781188}, {0, 0.707106781188, -0.707106781188} };
const double _20DOP::msDirectionNormalized[][3] = {  {0.577350269189, 0.577350269189, 0.577350269189}, {-0.577350269189, 0.577350269189, 0.577350269189}, {0.577350269189, -0.577350269189, 0.577350269189}, {0.577350269189, 0.577350269189, -0.577350269189},
                                          {0.707106781188, 0.707106781188, 0}, {0.707106781188, -0.707106781188, 0}, {0.707106781188, 0, 0.707106781188}, {0.707106781188, 0, -0.707106781188}, {0, 0.707106781188, 0.707106781188}, {0, 0.707106781188, -0.707106781188} };
const double _26DOP::msDirectionNormalized[][3] = {  {1, 0, 0}, {0, 1, 0}, {0, 0, 1},
                                          {0.577350269189, 0.577350269189, 0.577350269189}, {-0.577350269189, 0.577350269189, 0.577350269189}, {0.577350269189, -0.577350269189, 0.577350269189}, {0.577350269189, 0.577350269189, -0.577350269189},
                                          {0.707106781188, 0.707106781188, 0}, {0.707106781188, -0.707106781188, 0}, {0.707106781188, 0, 0.707106781188}, {0.707106781188, 0, -0.707106781188}, {0, 0.707106781188, 0.707106781188}, {0, 0.707106781188, -0.707106781188} };

const double (*kDOP::Direction() const)[3] {return msDirection;}
const double (*_6DOP::Direction() const)[3] {return msDirection;}
const double (*_8DOP::Direction() const)[3] {return msDirection;}
const double (*_12DOP::Direction() const)[3] {return msDirection;}
const double (*_14DOP::Direction() const)[3] {return msDirection;}
const double (*_18DOP::Direction() const)[3] {return msDirection;}
const double (*_20DOP::Direction() const)[3] {return msDirection;}
const double (*_26DOP::Direction() const)[3] {return msDirection;}

const double (*kDOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_6DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_8DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_12DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_14DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_18DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_20DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
const double (*_26DOP::DirectionNormalized() const)[3] {return msDirectionNormalized;}
}  // namespace Kratos.

