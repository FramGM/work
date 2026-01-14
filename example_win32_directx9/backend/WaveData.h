#pragma once
#include "../imgui/implot.h"
#include <corecrt_math.h>

struct WaveData
{
	double X, Amp, Freq, Offset;
	double m_dlTimeDiff;
	WaveData(double x, double amp, double freq, double offset, double dlStartTime) { X = x; Amp = amp; Freq = freq; Offset = offset; m_dlTimeDiff = ImGui::GetTime() - dlStartTime; }
};

ImPlotPoint SineWave(int idx, void* data)
{
	WaveData* wd = (WaveData*)data;
	double x = wd->m_dlTimeDiff + idx * wd->X;
	return ImPlotPoint(x, wd->Offset + wd->Amp * sin(2 * 3.14 * wd->Freq * x));
}

ImPlotPoint CosWave(int idx, void* data)
{
	WaveData* wd = (WaveData*)data;
	double x = wd->m_dlTimeDiff + idx * wd->X;
	return ImPlotPoint(x, wd->Offset + wd->Amp * cos(2 * 3.14 * wd->Freq * x));
}
