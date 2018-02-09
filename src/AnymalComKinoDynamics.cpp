/*
 * AnymalComKinoDynamics.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: farbod
 */

#include "ocs2_anymal_switched_model/dynamics/AnymalComKinoDynamics.h"

namespace anymal {

AnymalComKinoDynamics::AnymalComKinoDynamics(const scalar_t& gravitationalAcceleration,
		const switched_model::Options& options)

: Base(new AnymalKinematics(), new AnymalCom(), gravitationalAcceleration, options)
{}

AnymalComKinoDynamics::AnymalComKinoDynamics(const AnymalComKinoDynamics& rhs)
: Base(rhs)
{}

AnymalComKinoDynamics* AnymalComKinoDynamics::clone() const {

	return new AnymalComKinoDynamics(*this);
}

} //end of namespace anymal
