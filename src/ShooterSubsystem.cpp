#include <WPILib.h>

#include "ShooterSubsystem.h"
#include "RobotSubsystem.h"
#include "RobotConstants.h"

ShooterSubsystem::ShooterSubsystem(std::string name)
    : RobotSubsystem(name)
    , m_joystick(NULL)
	, m_feedermotor(NULL)
    , m_loadermotor(NULL)
    , m_shootermotor1(NULL)
    , m_shootermotor2(NULL)
{
}

ShooterSubsystem::~ShooterSubsystem()
{   
}

/********************************** Init Routines *************************************/

void ShooterSubsystem::RobotInit() 
{
    /* Create all of the input and output objects */

    m_joystick = new Joystick(0);

    m_feedermotor = new Victor(c_feedermotor_PWMid);
    m_loadermotor = new Victor(c_loadermotor_PWMid);
    m_shootermotor1 = new Victor(c_shootermotor1_PWMid);
    m_shootermotor2 = new Victor(c_shootermotor2_PWMid);
}

void ShooterSubsystem::DisabledInit() 
{
}

void ShooterSubsystem::TeleopInit() 
{
}

void ShooterSubsystem::AutonomousInit() 
{
}

void ShooterSubsystem::TestInit() 
{
}

/********************************** Periodic Routines *************************************/

void ShooterSubsystem::DisabledPeriodic()  
{
    /* Disable all of the motors */
    m_feedermotor->Set(0, 0);
    m_loadermotor->Set(0, 0);
    m_shootermotor1->Set(0, 0);
    m_shootermotor2->Set(0, 0);
}

void ShooterSubsystem::TeleopPeriodic() 
{
    /* Control the speed of the shooter flywheel with the throttle.
     * GetThrottle() returns a float between -1 and 1
     * With the Logitech 3d Pro Extreme Joystick fully forwards is -1 
     * and fully backwards is 1.
     * m_jsthrottle gives the value of the throttle between 0 and 1
     * with 1 being fully forwards and 0 being fully backwards.
     *
     * The motors of the flywheel are set to the value of the throttle.
     */
    float m_jsthrottle = ((m_joystick->GetThrottle() * -1) + 1)/2;
    m_shootermotor1->Set(-m_jsthrottle, 0);
    m_shootermotor2->Set(-m_jsthrottle, 0);

    /*
     * Use the thumb button on the joystick
     * to to control the feeder and loader motors.
     */
    if( m_joystick->GetRawButton(c_jsthumb_BTNid) ) {
        m_feedermotor->Set(1, 0);
        m_loadermotor->Set(1, 0);
    }
    else {
        m_feedermotor->Set(0, 0);
        m_loadermotor->Set(0, 0);
    }
}

void ShooterSubsystem::AutonomousPeriodic() 
{
}

void ShooterSubsystem::TestPeriodic() 
{
    /* Use the numbered buttons on the top to control
     * the motors individually for testing purposes.
     *
     * Make sure the follow information has not changed.
     * =================================================
     * Feeder Motor         [PWM 7]     [Button 3] 
     * Loader Motor         [PWM 5]     [Button 5]
     * Shooter Motor 1      [PWM 3]     [Button 4]
     * Shooter Motor 2      [PWM 6]     [Button 6]
     *
     */

    if (m_joystick->GetRawButton(3))
        m_feedermotor->Set(1, 0);
    else
        m_feedermotor->Set(0, 0);


    if (m_joystick->GetRawButton(5))
        m_loadermotor->Set(1, 0);
    else
        m_loadermotor->Set(0, 0);


    if (m_joystick->GetRawButton(4))
        m_shootermotor2->Set(-1, 0);
    else
        m_shootermotor2->Set(0, 0);


    if (m_joystick->GetRawButton(6))
        m_shootermotor1->Set(-1, 0);
    else
        m_shootermotor1->Set(0, 0);
}