#pragma once

class CeresSolverWarping {

public:
    CeresSolverWarping(unsigned int width, unsigned int height)
	{
		m_width = width;
		m_height = height;

        h_x_double = new double2[width * height];
        h_a_double = new double[width * height];

        for (int i = 0; i < (int)width * (int)height; i++)
        {
            h_x_double[i].x = 0.0;
            h_x_double[i].y = 0.0;
            h_a_double[i] = 0.0;
        }
	}

    ~CeresSolverWarping()
	{
		
	}

    // !returns total time taken for solve, in milliseconds
    float solve(float2* h_x_float, float* h_a_float, float2* h_urshape, float2* h_constraints, float* h_mask, float weightFit, float weightReg);

private:

	double2* h_x_double;
    double* h_a_double;
	int m_width, m_height;
};
#ifndef USE_CERES
inline float CeresSolverWarping::solve(float2* h_x_float, float* h_a_float, float2* h_urshape, float2* h_constraints, float* h_mask, float weightFit, float weightReg)
{
    return 0.0f;
}
#endif