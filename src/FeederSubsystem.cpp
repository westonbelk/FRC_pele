#include <WPILib.h>

#include "FeederSubsystem.h"
#include "RobotSubsystem.h"
#include "RobotConstants.h"

FeederSubsystem::FeederSubsystem(std::string name)
    : RobotSubsystem(name)
    , m_joystick(NULL)
    , m_lfeedermotor(NULL)
    , m_rfeedermotor(NULL)
{
}

FeederSubsystem::~FeederSubsystem()
{   
}

/********************************** Init Routines *************************************/

void FeederSubsystem::RobotInit() 
{
    m_joystick = new Joystick(0);

    m_lfeedermotor = new Victor(c_lfeedermotor_PWMid);
    m_rfeedermotor = new Victor(c_rfeedermotor_PWMid);
}

void FeederSubsystem::DisabledInit() 
{
}

void FeederSubsystem::TeleopInit() 
{
    /* Enable the feeder motors */
    m_lfeedermotor->Set(1, 0);
    m_rfeedermotor->Set(1, 0);

}

void FeederSubsystem::AutonomousInit() 
{
}

void FeederSubsystem::TestInit() 
{
}

/********************************** Periodic Routines *************************************/

void FeederSubsystem::DisabledPeriodic()  
{
        /* Disable the feeder motors */
    m_lfeedermotor->Set(0, 0);
    m_rfeedermotor->Set(0, 0);
}

void FeederSubsystem::TeleopPeriodic() 
{
}

void FeederSubsystem::AutonomousPeriodic() 
{
    if (m_joystick->GetRawButton(c_jsthumb_id)) {
        // Fire!
    }
}

void FeederSubsystem::TestPeriodic() 
{
}
