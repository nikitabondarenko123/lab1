#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
#include "MotorCtrl.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Regulator(struct FB_Regulator* inst)
{
	// Интегратор в прямой цепи
	/*inst->u += (inst->k_p * inst->e <= inst->max_abs_value ? inst->k_p * inst->e : inst->max_abs_value) + 
		inst->k_i * inst->dt * inst->e_prev - 
		(inst->k_p * inst->e_prev <= inst->max_abs_value ? inst->k_p * inst->e_prev : inst->max_abs_value);
	
	//Ограничение напряжения
	if (inst->u > inst->max_abs_value)
		inst->u = inst->max_abs_value;
	*/
	
	// Интегратор в обратной цепи
	inst->u_raw = (inst->k_p * inst->e <= inst->max_abs_value ? inst->k_p * inst->e : inst->max_abs_value) - 
		(inst->k_p * inst->e_prev <= inst->max_abs_value ? inst->k_p * inst->e_prev : inst->max_abs_value) + 
		inst->k_i * inst->dt * inst->e + (inst->u - inst->iyOld);  
	
	if (inst->u_raw <= inst->max_abs_value)
		inst->u = inst->u_raw;
	else
	{
		inst->u_raw = (inst->u_raw + inst->max_abs_value) / 2;  //truncating-scheme input
		inst->u = inst->max_abs_value;
	}
	inst->iyOld = inst->u - inst->u_raw;  //updating old truncating-scheme output
}

