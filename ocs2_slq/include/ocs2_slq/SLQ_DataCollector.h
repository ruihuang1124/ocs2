/*
 * SLQ_DataCollector.h
 *
 *  Created on: Aug 5, 2018
 *      Author: farbod
 */

#ifndef SLQ_DATACOLLECTOR_OCS2_H_
#define SLQ_DATACOLLECTOR_OCS2_H_

#include <vector>
#include <Eigen/Dense>

#include <ocs2_slq/SLQ_BASE.h>

namespace ocs2 {

/**
 * Collects the required data from SLQ instance. It uses swap method wherever it is possible.
 *
 * @tparam STATE_DIM: Dimension of the state space.
 * @tparam INPUT_DIM: Dimension of the control input space.
 * @tparam LOGIC_RULES_T: Logic Rules type (default NullLogicRules).
 */
template <size_t STATE_DIM, size_t INPUT_DIM, class LOGIC_RULES_T>
class SLQ_DataCollector
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	typedef SLQ_BASE<STATE_DIM, INPUT_DIM, LOGIC_RULES_T> slq_t;

	typedef typename slq_t::controller_array_t controller_array_t;
	typedef typename slq_t::size_array_t   size_array_t;
	typedef typename slq_t::scalar_t       scalar_t;
	typedef typename slq_t::scalar_array_t scalar_array_t;
	typedef typename slq_t::eigen_scalar_t        eigen_scalar_t;
	typedef typename slq_t::eigen_scalar_array_t  eigen_scalar_array_t;
	typedef typename slq_t::eigen_scalar_array2_t eigen_scalar_array2_t;
	typedef typename slq_t::state_vector_t        state_vector_t;
	typedef typename slq_t::state_vector_array_t  state_vector_array_t;
	typedef typename slq_t::state_vector_array2_t state_vector_array2_t;
	typedef typename slq_t::input_vector_array_t  input_vector_array_t;
	typedef typename slq_t::input_vector_array2_t input_vector_array2_t;
	typedef typename slq_t::input_state_matrix_array_t  input_state_matrix_array_t;
	typedef typename slq_t::input_state_matrix_array2_t input_state_matrix_array2_t;
	typedef typename slq_t::state_matrix_array_t  state_matrix_array_t;
	typedef typename slq_t::state_matrix_t        state_matrix_t;
	typedef typename slq_t::state_matrix_array2_t state_matrix_array2_t;
	typedef typename slq_t::input_matrix_array_t  input_matrix_array_t;
	typedef typename slq_t::input_matrix_array2_t input_matrix_array2_t;
	typedef typename slq_t::state_input_matrix_array_t  state_input_matrix_array_t;
	typedef typename slq_t::state_input_matrix_array2_t state_input_matrix_array2_t;
	typedef typename slq_t::constraint1_vector_array_t  constraint1_vector_array_t;
	typedef typename slq_t::constraint1_vector_array2_t constraint1_vector_array2_t;
	typedef typename slq_t::constraint1_state_matrix_array_t  constraint1_state_matrix_array_t;
	typedef typename slq_t::constraint1_state_matrix_array2_t constraint1_state_matrix_array2_t;
	typedef typename slq_t::constraint1_input_matrix_array_t  constraint1_input_matrix_array_t;
	typedef typename slq_t::constraint1_input_matrix_array2_t constraint1_input_matrix_array2_t;
	typedef typename slq_t::control_constraint1_matrix_array_t  control_constraint1_matrix_array_t;
	typedef typename slq_t::control_constraint1_matrix_array2_t control_constraint1_matrix_array2_t;
	typedef typename slq_t::constraint2_vector_array_t  constraint2_vector_array_t;
	typedef typename slq_t::constraint2_vector_array2_t constraint2_vector_array2_t;
	typedef typename slq_t::constraint2_state_matrix_array_t  constraint2_state_matrix_array_t;
	typedef typename slq_t::constraint2_state_matrix_array2_t constraint2_state_matrix_array2_t;

	/**
	 * Default constructor.
	 */
	SLQ_DataCollector() = default;

	/**
	 * Default destructor.
	 */
	~SLQ_DataCollector() = default;

	/**
	 * Collects the required data from SLQ instance. It uses swap method wherever it is possible.
	 *
	 * @param constSlqPtr: A pointer to the SLQ instance.
	 * @return True if number of partitions is changed.
	 */
	bool collect(const slq_t* constSlqPtr);

	/******************
	 * SLQ variables image
	 ******************/
	scalar_t initTime_;
	scalar_t finalTime_;
	state_vector_t initState_;

	size_t initActivePartition_;
	size_t finalActivePartition_;
	size_t numPartitions_ = 0;
	scalar_array_t partitioningTimes_;

	controller_array_t optimizedControllersStock_;

//	std::vector<scalar_array_t> optimizedTimeTrajectoriesStock_;
//	std::vector<size_array_t> 	optimizedEventsPastTheEndIndecesStock_;
//	state_vector_array2_t		optimizedStateTrajectoriesStock_;
//	input_vector_array2_t  		optimizedInputTrajectoriesStock_;

	std::vector<scalar_array_t> nominalTimeTrajectoriesStock_;
	std::vector<size_array_t> 	nominalEventsPastTheEndIndecesStock_;
	state_vector_array2_t		nominalStateTrajectoriesStock_;
	input_vector_array2_t  		nominalInputTrajectoriesStock_;

	state_matrix_array2_t 		AmTrajectoriesStock_;
	state_input_matrix_array2_t BmTrajectoriesStock_;

	std::vector<size_array_t>         nc1TrajectoriesStock_;  	// nc1: Number of the Type-1  active constraints
	constraint1_vector_array2_t       EvTrajectoriesStock_;
	constraint1_state_matrix_array2_t CmTrajectoriesStock_;
	constraint1_input_matrix_array2_t DmTrajectoriesStock_;

	std::vector<size_array_t> 			nc2TrajectoriesStock_;  // nc2: Number of the Type-2 active constraints
	constraint2_vector_array2_t 		HvTrajectoriesStock_;
	constraint2_state_matrix_array2_t 	FmTrajectoriesStock_;
	std::vector<size_array_t>			nc2FinalStock_;
	constraint2_vector_array2_t			HvFinalStock_;
	constraint2_state_matrix_array2_t 	FmFinalStock_;

	eigen_scalar_array2_t		qFinalStock_;
	state_vector_array2_t		QvFinalStock_;
	state_matrix_array2_t		QmFinalStock_;

	eigen_scalar_array2_t 		qTrajectoriesStock_;
	state_vector_array2_t 		QvTrajectoriesStock_;
	state_matrix_array2_t 		QmTrajectoriesStock_;
	input_vector_array2_t		RvTrajectoriesStock_;
	input_matrix_array2_t		RmTrajectoriesStock_;
	input_state_matrix_array2_t	PmTrajectoriesStock_;

	input_matrix_array2_t RmInverseTrajectoriesStock_;
	state_matrix_array2_t AmConstrainedTrajectoriesStock_;
	state_matrix_array2_t QmConstrainedTrajectoriesStock_;
	state_vector_array2_t QvConstrainedTrajectoriesStock_;
	input_matrix_array2_t RmConstrainedTrajectoriesStock_;
	control_constraint1_matrix_array2_t DmDagerTrajectoriesStock_;
	input_vector_array2_t   	EvProjectedTrajectoriesStock_;  // DmDager * Ev
	input_state_matrix_array2_t CmProjectedTrajectoriesStock_;  // DmDager * Cm
	input_matrix_array2_t   	DmProjectedTrajectoriesStock_;  // DmDager * Dm
	state_input_matrix_array2_t BmConstrainedTrajectoriesStock_;
	input_state_matrix_array2_t PmConstrainedTrajectoriesStock_;
	input_vector_array2_t 		RvConstrainedTrajectoriesStock_;

	// terminal cost which is interpreted as the Heuristic function
	eigen_scalar_t sHeuristics_;
	state_vector_t SvHeuristics_;
	state_matrix_t SmHeuristics_;

	std::vector<scalar_array_t>	SsTimeTrajectoriesStock_;
	std::vector<scalar_array_t> SsNormalizedTimeTrajectoriesStock_;
	std::vector<size_array_t> 	SsNormalizedEventsPastTheEndIndecesStock_;
	state_matrix_array2_t       SmTrajectoriesStock_;
	state_vector_array2_t       SvTrajectoriesStock_;
	state_vector_array2_t       SveTrajectoriesStock_;
	eigen_scalar_array2_t 		sTrajectoriesStock_;

	/******************
	 * SLQ missing variables
	 ******************/
	state_vector_array2_t nominalFlowMapTrajectoriesStock_;

protected:
	/**
	 * Resizes the data of the other-class's member.
	 *
	 * @param numPartitions: Number of partitions.
	 * @param otherPtr: A pointer to the OTHER_CLASS instance
	 * @return True if number of partitions is changed.
	 */
	void resizeDataContainer(const size_t& numPartitions);

	/**
	 * Calculates the time derivatives of the nominal state trajectory.
	 *
	 * @param [in] constSlqPtr: A pointer to the SLQ instance.
	 * @param [in] timeTrajectoriesStock: The time trajectory stamp.
	 * @param [in] stateTrajectoriesStock: The state trajectory.
	 * @param [in] inputTrajectoriesStock: The control input trajectory.
	 * @param [out] flowMapTrajectoriesStock: An array of the time
	 * derivatives of the nominal state trajectory.
	 */
	void calculateFlowMap(
			const slq_t* constSlqPtr,
			const std::vector<scalar_array_t>& timeTrajectoriesStock,
			const state_vector_array2_t& stateTrajectoriesStock,
			const input_vector_array2_t& inputTrajectoriesStock,
			state_vector_array2_t& flowMapTrajectoriesStock);

};

} // namespace ocs2

#include "implementation/SLQ_DataCollector.h"

#endif /* SLQ_DATACOLLECTOR_OCS2_H_ */
