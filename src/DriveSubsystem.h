#ifndef _DRIVE_SUBSYSTEM_H
#define _DRIVE_SUBSYSTEM_H

#include <WPILib.h>
#include <Victor.h>

#include "RobotSubsystem.h"

class DriveSubsystem : public RobotSubsystem {
private:
    Joystick* m_joystick;
    Victor* m_frmotor;
    Victor* m_flmotor;
    Victor* m_rrmotor;
    Victor* m_rlmotor;
    RobotDrive* m_robotDrive;

public:
    DriveSubsystem(std::string name = "drive");
    virtual ~DriveSubsystem();

    /********************************** Init Routines **********************************/

    virtual void RobotInit();
    virtual void DisabledInit();
    virtual void TeleopInit();
    virtual void AutonomousInit();
    virtual void TestInit();

    /********************************** Periodic Routines
     * *************************************/

    virtual void DisabledPeriodic();
    virtual void AutonomousPeriodic();
    virtual void TeleopPeriodic();
    virtual void TestPeriodic();
};
#endif
