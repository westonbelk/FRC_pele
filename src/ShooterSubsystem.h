#ifndef _SHOOTER_SUBSYSTEM_H
#define _SHOOTER_SUBSYSTEM_H

#include <WPILib.h>
#include <Victor.h>

#include "RobotSubsystem.h"

class ShooterSubsystem : public RobotSubsystem {
private:
    Joystick* m_joystick;
    Victor* m_feedermotor;
    Victor* m_loadermotor;
    Victor* m_shootermotor1;
    Victor* m_shootermotor2;

public:
    ShooterSubsystem(std::string name = "feeder");
    virtual ~ShooterSubsystem();

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
