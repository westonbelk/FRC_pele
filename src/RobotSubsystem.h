#ifndef ROBOT_SUBSYSTEM_H
#define ROBOT_SUBSYSTEM_H

class RobotSubsystem
{
private:
    std::string m_name;
    int m_counter;
    
public:
    RobotSubsystem(std::string name="unknown");
    virtual ~RobotSubsystem();

    const char *GetName(void);
	
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
