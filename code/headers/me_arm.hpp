#pragma once

#include <calculate_inverse_kinematics.hpp>
#include <robot_arm_interface.hpp>
#include <servo.hpp>
#include <vector3.hpp>
namespace r2d2::robot_arm {
    /**
     * @brief
     * Class to controll robot arms that have 3 axis and 2 joints and are
     * controlled with a servo.
     */

    class me_arm_c : public robot_arm_interface_c {
    private:
        vector3i_c location_end_effector;
        servo_c servo1, servo2, servo3;
        calculate_inverse_kinematics_c &calculator;

    public:
        /**
         * @brief
         * me_arm_c constructor.
         * @detailed
         * Created a me_arm_c object.
         * @param servo_c servo1 - servo that controls the first joint.
         * @param servo_c servo2 - servo that controls the second joint.
         * @param servo_c servo3 - servo that controls the direction of the arm.
         * head/end effector.
         * @param calculate_inverse_kinematics_c calculator - the class that
         * calculates the angles for the two arm joints.
         */
        me_arm_c(servo_c servo1, servo_c servo2, servo_c servo3,
                 calculate_inverse_kinematics_c &calculator);

        /**
         * @brief
         * This function moves the robot arm head to the given coordinate.
         *
         * @param const vector3i_c &coordinate - int x, int y coordinate with
         * int z as direction in degrees.
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;

        /**
         * @brief
         * This function moves the robot arm head to the given coordinate.
         *
         * @param const vector3i_c &coordinate - int x, int y coordinate with
         * int z as direction in degrees.
         * @param uint16_t speed - the speed at which the arm has to move.
         */
        void move_head_to_coordinate(const vector3i_c &coordinate,
                                     uint16_t speed) override;
        /**
         * @brief
         * This function is not supported by the me arm.
         * @detailed
         * This function should rotate the head of the robot arm to grab
         * objects. However the me arm does not have that capability. This
         * function only contains a hwlib::cout that will tell you that this is
         * not supported.
         *
         * @param int16_t rotation - degrees of rotations of the head.
         */
        void rotate_head(int16_t rotation) override;
    };
} // namespace r2d2::robot_arm