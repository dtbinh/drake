#ifndef __DrakeCollisionPointPair_H__
#define __DrakeCollisionPointPair_H__

#include <Eigen/Dense>
#include <Eigen/StdVector>

#include "Element.h"

#include "DLLEXPORT_drakeCollision.h"

namespace DrakeCollision
{
  class DLLEXPORT_drakeCollision PointPair {
    public:
      PointPair(const ElementId idA, const ElementId idB,
                const Eigen::Vector3d ptA, const Eigen::Vector3d ptB,
                const Eigen::Vector3d normal, double distance)
      : idA(idA), idB(idB), ptA(ptA),
        ptB(ptB), normal(normal),
        distance(distance)
      {}

      const ElementId idA;
      const ElementId idB;
      const Eigen::Vector3d ptA;
      const Eigen::Vector3d ptB;
      const Eigen::Vector3d normal;
      double distance;

      void getResults(Eigen::Vector3d& ptA, Eigen::Vector3d& ptB, Eigen::Vector3d& normal);
      void getResults(Eigen::Vector3d& ptA, Eigen::Vector3d& ptB, Eigen::Vector3d& normal, double& distance);

      bool operator < (const PointPair& pt) const
      {
        return (distance < pt.distance);
      }

      bool operator == (const PointPair& pt) const
      {
        return (distance == pt.distance);
      }

      bool operator != (const PointPair& pt) const
      {
        return (distance != pt.distance);
      }

      bool operator <= (const PointPair& pt) const
      {
        return (distance <= pt.distance);
      }

      bool operator > (const PointPair& pt) const
      {
        return (distance > pt.distance);
      }

      bool operator >= (const PointPair& pt) const
      {
        return (distance >= pt.distance);
      }
  };
}
#endif
