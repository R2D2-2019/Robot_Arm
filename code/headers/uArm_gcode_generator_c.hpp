#include "gcode_generator_c.hpp"

namespace r2d2::robot_arm {

    class uArm_gcode_generator_c : public gcode_generator_c {
    public:
        uArm_gcode_generator_c() = default;
        ~uArm_gcode_generator_c() = default;

        char *coordinate_to_gcode(const coordinate_3D_c &coordinate,
                                  char *destination) const override;
    };
} // namespace r2d2::robot_arm