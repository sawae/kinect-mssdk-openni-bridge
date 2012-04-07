#pragma once
#include "base.h"
#include "MSRKinectRequirement.h"

class MSRKinectFrameContextBase
{
public:
	XN_DECLARE_EVENT_0ARG(ChangeEvent, ChangeEventInterface);

protected:
	HANDLE m_hNextFrameEvent;

	BOOL m_bRunning;

	XnUInt32 m_nFrameID;
	XnUInt64 m_lTimestamp;

	BOOL m_bMirror; // Note; flag only
	ChangeEvent m_mirrorChangeEvent;
	BOOL m_bCalibrateViewPoint; // Note: flag only
	ChangeEvent m_calibrateViewPointChangeEvent;

	MSRKinectRequirement* m_pRequirement;

public:
	MSRKinectRequirement* GetRequirement() { return m_pRequirement; }

	XnUInt32 GetFrameID() const { return m_nFrameID; }
	XnUInt64 GetTimestamp() const { return m_lTimestamp; }
	BOOL IsRunning() const { return m_bRunning; }

	BOOL IsMirror() const { return m_bMirror; }
	void SetMirror(BOOL value) { m_bMirror = value; m_mirrorChangeEvent.Raise(); }
	ChangeEvent* GetMirrorChangeEvent() { return &m_mirrorChangeEvent; }

	BOOL IsCalibrateViewPoint() const { return m_bCalibrateViewPoint; }
	void SetCalibrateViewPoint(BOOL value) { m_bCalibrateViewPoint = value; m_calibrateViewPointChangeEvent.Raise(); }
	ChangeEvent* GetCalibrateViewPointChangeEvent() { return &m_calibrateViewPointChangeEvent; }

protected:
	MSRKinectFrameContextBase(MSRKinectRequirement* pRequirement, HANDLE hNextFrameEvent) :
		m_pRequirement(pRequirement),
		m_hNextFrameEvent(hNextFrameEvent),
		m_bRunning(FALSE),
		m_nFrameID(0), m_lTimestamp(0),
		m_bMirror(FALSE), m_bCalibrateViewPoint(FALSE)
	{
	}

public:
	virtual ~MSRKinectFrameContextBase() {}
};
