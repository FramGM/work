#pragma once

struct ImPlotPoint;

class Wave
{
public:
	Wave(double x, double amp, double freq, double offset, int iPointsCount) { m_dlX = x; m_dlAmp = amp; m_dlFreq = freq; m_dlOffset = offset; m_iPointsCount = iPointsCount; }

	virtual ImPlotPoint GetWavePoint(void* data, int iIdx) = 0;
	int GetPointsCount() { return m_iPointsCount; }

protected:
	double m_dlX, m_dlAmp, m_dlFreq, m_dlOffset;
	int m_iPointsCount;
};

class SinWave : public Wave
{
public:
	SinWave(double x, double amp, double freq, double offset, int iPointsCount) : Wave(x, amp, freq, offset, iPointsCount) {}

	ImPlotPoint GetWavePoint(void* data, int iIdx) override;
};

class CosWave : public Wave
{
public:
	CosWave(double x, double amp, double freq, double offset, int iPointsCount) : Wave(x, amp, freq, offset, iPointsCount) {}

	ImPlotPoint GetWavePoint(void* data, int iIdx) override;
};