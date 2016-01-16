#ifndef _CAMERA_SUBSYSTEM_H
#define _CAMERA_SUBSYSTEM_H

#include <WPILib.h>

#include "RobotSubsystem.h"

class CameraSubsystem : public RobotSubsystem {
private:

	#if AXIS_CAMERA
		AxisCamera *m_camera;
		Image *m_frame;
	#endif

public:
    CameraSubsystem(std::string name = "camera");
    virtual ~CameraSubsystem();

    /********************************** Init Routines **********************************/

    virtual void RobotInit();
    virtual void DisabledInit();
    virtual void TeleopInit();
    virtual void AutonomousInit();
    virtual void TestInit();

    /********************************** Periodic Routines **********************************/

    virtual void DisabledPeriodic();
    virtual void AutonomousPeriodic();
    virtual void TeleopPeriodic();
    virtual void TestPeriodic();
};
#endif
