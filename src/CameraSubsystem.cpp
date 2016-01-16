#include <WPILib.h>

#include "CameraSubsystem.h"
#include "RobotSubsystem.h"
#include "RobotConstants.h"

CameraSubsystem::CameraSubsystem(std::string name)
    : RobotSubsystem(name)
{
}

CameraSubsystem::~CameraSubsystem() {}

/********************************** Init Routines **********************************/

void CameraSubsystem::RobotInit()
{
	#if USB_CAMERA
		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	#endif
}

void CameraSubsystem::DisabledInit() {}

void CameraSubsystem::TeleopInit() {}

void CameraSubsystem::AutonomousInit() {}

void CameraSubsystem::TestInit() {}

/********************************** Periodic Routines **********************************/

void CameraSubsystem::DisabledPeriodic() {}

void CameraSubsystem::TeleopPeriodic() {}

void CameraSubsystem::AutonomousPeriodic() {}

void CameraSubsystem::TestPeriodic() {}
