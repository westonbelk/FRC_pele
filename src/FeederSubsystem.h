#ifndef _FEEDER_SUBSYSTEM_H
#define _FEEDER_SUBSYSTEM_H

#include <WPILib.h>
#include <Victor.h>

#include "RobotSubsystem.h"

class FeederSubsystem : public RobotSubsystem
{
private:
    Joystick   *m_joystick;
    Victor     *m_lfeedermotor;
    Victor     *m_rfeedermotor;
    
public:
    FeederSubsystem(std::string name="feeder");
    virtual ~FeederSubsystem();
    
    /********************************** Init Routines *************************************/

    virtual void RobotInit();
    virtual void DisabledInit();
    virtual void TeleopInit();
    virtual void AutonomousInit();
    virtual void TestInit();

    /********************************** Periodic Routines *************************************/
    
    virtual void DisabledPeriodic();
    virtual void AutonomousPeriodic();
    virtual void TeleopPeriodic();  
    virtual void TestPeriodic();
};
#endif