
FUNCTION_BLOCK FB_Integrator
	VAR_INPUT
		in : REAL;
	END_VAR
	VAR_OUTPUT
		out : REAL;
	END_VAR
	VAR
		dt : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Motor
	VAR_INPUT
		u : REAL;
	END_VAR
	VAR_OUTPUT
		w : REAL;
		phi : REAL;
	END_VAR
	VAR
		integrator : FB_Integrator;
		Tm : REAL;
		ke : REAL;
		dt : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Regulator
	VAR_INPUT
		e : REAL;
		e_prev : REAL;
	END_VAR
	VAR_OUTPUT
		u : REAL;
	END_VAR
	VAR
		u_raw : REAL;
		count : USINT;
		k_p : REAL;
		k_i : REAL;
		integrator : FB_Integrator;
		iyOld : REAL;
		max_abs_value : REAL;
		dt : REAL;
	END_VAR
END_FUNCTION_BLOCK
