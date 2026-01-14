#include "Waves.h"
#include <corecrt_math.h>
#include "../imgui/implot.h"

ImPlotPoint SinWave::GetWavePoint(void* data, int iIdx)
{
	double x = iIdx * this->m_dlX;
	return ImPlotPoint(x, this->m_dlOffset + this->m_dlAmp * sin(2 * 3.14 * this->m_dlFreq * x));
}

ImPlotPoint CosWave::GetWavePoint(void* data, int iIdx)
{
	double x = iIdx * this->m_dlX;
	return ImPlotPoint(x, this->m_dlOffset + this->m_dlAmp * cos(2 * 3.14 * this->m_dlFreq * x));
}
