#include <calculate_inverse_kinematics.hpp>

namespace r2d2::robot_arm {
    calculate_inverse_kinematics_c::calculate_inverse_kinematics_c(
        uint16_t arm_length1, uint16_t arm_length2)
        : arm_length1(arm_length1), arm_length2(arm_length2) {
    }
    void calculate_inverse_kinematics_c::set_position_end_effector(
        vector3i_c coordinate) {

        uint16_t line_a = arm_length2;
        uint16_t line_b = sqrt(pow(coordinate.x, 2.0) + pow(coordinate.y, 2.0));
        uint16_t line_c = arm_length1;

        angle_alpha =
            acos((pow(line_a, 2.0) - pow(line_b, 2.0) - pow(line_c, 2.0)) /
                 (-2 * line_b * line_c)) *
            180 / PI;

        angle_phi = atan2(coordinate.y, coordinate.x) * 180 / PI;

        angle_beta =
            acos(((pow(line_c, 2.0)) - pow(line_a, 2.0) - pow(line_b, 2.0)) /
                 (-2 * pow(line_a, 2.0) * pow(line_c, 2.0))) *
            180 / PI;

        angle_theta = angle_alpha + angle_phi;
    }
    uint16_t calculate_inverse_kinematics_c::get_angle_theta() {
        return angle_theta;
    }

    uint16_t calculate_inverse_kinematics_c::get_angle_beta() {
        return angle_beta;
    }

} // namespace r2d2::robot_arm
