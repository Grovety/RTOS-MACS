/// @file macs_timer.hpp
/// @brief �������.
/// @details ��������� ���������� ��� ������� � ���������� ���������.
/// @copyright AstroSoft Ltd, 2015-2016

#pragma once

#include "macs_common.hpp"

/// @brief ������� ����� ��� ��������, ���������� �� ������� �� �������.
class TimerAction
{
public:
	/// @brief ��������, ����������� �������� �� ������� �� �������.
	virtual void operator()() = 0;
};

struct TimerData;

/// @brief ������.
class Timer
{
public:
	/// @brief �����������. ������� ������ ��� ���������� ��������.
	Timer();

	/// @brief ����������.
	~Timer();

	/// @brief �������� ���� �������.
	enum MeasureMode
	{
		Microseconds, ///< ������������, [���]
		Milliseconds ///< ������������, [��]
	};

	/// @brief �������������� ������.
	/// @param period ���������� ����� ����� ��������� �� �������.
	/// @param mode �������� ������ ����.
	/// @param action ��������, ����������� �� ������� �� �������.
	/// @return [ResultOk](@ref maks::ResultOk) - ���� �������� ��������� �������, ��� ������ - � ��������� ������.
	Result Initialize(uint period, MeasureMode mode, TimerAction * action);

	/// @brief ����������� ��� �������, ������� ��������.
	/// @return [ResultOk](@ref maks::ResultOk) - ���� �������� ��������� �������, ��� ������ - � ��������� ������.
	Result DeInitialize();

	/// @brief �������� ������ ����� � ������� ��������.
	/// @param immediate_tick true - ���������� ������ ����� ��� �������, false - ������ ������ ������ ������ �� ��������� ������� �������.
	/// @return [ResultOk](@ref maks::ResultOk) - ���� �������� ��������� �������, ��� ������ - � ��������� ������.
	Result Start(bool immediate_tick = false);

	/// @brief ������������� ������ ����� � ������� ��������.
	/// @return [ResultOk](@ref maks::ResultOk) - ���� �������� ��������� �������, ��� ������ - � ��������� ������.
	Result Stop();

	ulong GetTick();
	void SetTick(ulong);
	ulong TicksFreq();
	ulong TicksMaxVal();

private:
	TimerData * m_timer;
};
