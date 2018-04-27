INCLUDEPATH += $$PWD/..


HEADERS += \
    $$PWD/detail/_features.hpp \
    $$PWD/detail/_fixes.hpp \
    $$PWD/detail/_noise.hpp \
    $$PWD/detail/_swizzle.hpp \
    $$PWD/detail/_swizzle_func.hpp \
    $$PWD/detail/_vectorize.hpp \
    $$PWD/detail/func_common.hpp \
    $$PWD/detail/func_exponential.hpp \
    $$PWD/detail/func_geometric.hpp \
    $$PWD/detail/func_integer.hpp \
    $$PWD/detail/func_matrix.hpp \
    $$PWD/detail/func_packing.hpp \
    $$PWD/detail/func_trigonometric.hpp \
    $$PWD/detail/func_vector_relational.hpp \
    $$PWD/detail/precision.hpp \
    $$PWD/detail/setup.hpp \
    $$PWD/detail/type_float.hpp \
    $$PWD/detail/type_gentype.hpp \
    $$PWD/detail/type_half.hpp \
    $$PWD/detail/type_int.hpp \
    $$PWD/detail/type_mat.hpp \
    $$PWD/detail/type_mat2x2.hpp \
    $$PWD/detail/type_mat2x3.hpp \
    $$PWD/detail/type_mat2x4.hpp \
    $$PWD/detail/type_mat3x2.hpp \
    $$PWD/detail/type_mat3x3.hpp \
    $$PWD/detail/type_mat3x4.hpp \
    $$PWD/detail/type_mat4x2.hpp \
    $$PWD/detail/type_mat4x3.hpp \
    $$PWD/detail/type_mat4x4.hpp \
    $$PWD/detail/type_vec.hpp \
    $$PWD/detail/type_vec1.hpp \
    $$PWD/detail/type_vec2.hpp \
    $$PWD/detail/type_vec3.hpp \
    $$PWD/detail/type_vec4.hpp \
    $$PWD/gtc/bitfield.hpp \
    $$PWD/gtc/color_space.hpp \
    $$PWD/gtc/constants.hpp \
    $$PWD/gtc/epsilon.hpp \
    $$PWD/gtc/functions.hpp \
    $$PWD/gtc/integer.hpp \
    $$PWD/gtc/matrix_access.hpp \
    $$PWD/gtc/matrix_integer.hpp \
    $$PWD/gtc/matrix_inverse.hpp \
    $$PWD/gtc/matrix_transform.hpp \
    $$PWD/gtc/noise.hpp \
    $$PWD/gtc/packing.hpp \
    $$PWD/gtc/quaternion.hpp \
    $$PWD/gtc/random.hpp \
    $$PWD/gtc/reciprocal.hpp \
    $$PWD/gtc/round.hpp \
    $$PWD/gtc/type_aligned.hpp \
    $$PWD/gtc/type_precision.hpp \
    $$PWD/gtc/type_ptr.hpp \
    $$PWD/gtc/ulp.hpp \
    $$PWD/gtc/vec1.hpp \
    $$PWD/gtx/associated_min_max.hpp \
    $$PWD/gtx/bit.hpp \
    $$PWD/gtx/closest_point.hpp \
    $$PWD/gtx/color_space.hpp \
    $$PWD/gtx/color_space_YCoCg.hpp \
    $$PWD/gtx/common.hpp \
    $$PWD/gtx/compatibility.hpp \
    $$PWD/gtx/component_wise.hpp \
    $$PWD/gtx/dual_quaternion.hpp \
    $$PWD/gtx/euler_angles.hpp \
    $$PWD/gtx/extend.hpp \
    $$PWD/gtx/extended_min_max.hpp \
    $$PWD/gtx/fast_exponential.hpp \
    $$PWD/gtx/fast_square_root.hpp \
    $$PWD/gtx/fast_trigonometry.hpp \
    $$PWD/gtx/gradient_paint.hpp \
    $$PWD/gtx/handed_coordinate_space.hpp \
    $$PWD/gtx/hash.hpp \
    $$PWD/gtx/integer.hpp \
    $$PWD/gtx/intersect.hpp \
    $$PWD/gtx/io.hpp \
    $$PWD/gtx/log_base.hpp \
    $$PWD/gtx/matrix_cross_product.hpp \
    $$PWD/gtx/matrix_decompose.hpp \
    $$PWD/gtx/matrix_interpolation.hpp \
    $$PWD/gtx/matrix_major_storage.hpp \
    $$PWD/gtx/matrix_operation.hpp \
    $$PWD/gtx/matrix_query.hpp \
    $$PWD/gtx/matrix_transform_2d.hpp \
    $$PWD/gtx/mixed_product.hpp \
    $$PWD/gtx/norm.hpp \
    $$PWD/gtx/normal.hpp \
    $$PWD/gtx/normalize_dot.hpp \
    $$PWD/gtx/number_precision.hpp \
    $$PWD/gtx/optimum_pow.hpp \
    $$PWD/gtx/orthonormalize.hpp \
    $$PWD/gtx/perpendicular.hpp \
    $$PWD/gtx/polar_coordinates.hpp \
    $$PWD/gtx/projection.hpp \
    $$PWD/gtx/quaternion.hpp \
    $$PWD/gtx/range.hpp \
    $$PWD/gtx/raw_data.hpp \
    $$PWD/gtx/rotate_normalized_axis.hpp \
    $$PWD/gtx/rotate_vector.hpp \
    $$PWD/gtx/scalar_multiplication.hpp \
    $$PWD/gtx/scalar_relational.hpp \
    $$PWD/gtx/spline.hpp \
    $$PWD/gtx/std_based_type.hpp \
    $$PWD/gtx/string_cast.hpp \
    $$PWD/gtx/transform.hpp \
    $$PWD/gtx/transform2.hpp \
    $$PWD/gtx/type_aligned.hpp \
    $$PWD/gtx/type_trait.hpp \
    $$PWD/gtx/vector_angle.hpp \
    $$PWD/gtx/vector_query.hpp \
    $$PWD/gtx/wrap.hpp \
    $$PWD/simd/common.h \
    $$PWD/simd/exponential.h \
    $$PWD/simd/geometric.h \
    $$PWD/simd/integer.h \
    $$PWD/simd/matrix.h \
    $$PWD/simd/packing.h \
    $$PWD/simd/platform.h \
    $$PWD/simd/trigonometric.h \
    $$PWD/simd/vector_relational.h \
    $$PWD/common.hpp \
    $$PWD/exponential.hpp \
    $$PWD/ext.hpp \
    $$PWD/fwd.hpp \
    $$PWD/geometric.hpp \
    $$PWD/glm.hpp \
    $$PWD/integer.hpp \
    $$PWD/mat2x2.hpp \
    $$PWD/mat2x3.hpp \
    $$PWD/mat2x4.hpp \
    $$PWD/mat3x2.hpp \
    $$PWD/mat3x3.hpp \
    $$PWD/mat3x4.hpp \
    $$PWD/mat4x2.hpp \
    $$PWD/mat4x3.hpp \
    $$PWD/mat4x4.hpp \
    $$PWD/matrix.hpp \
    $$PWD/packing.hpp \
    $$PWD/trigonometric.hpp \
    $$PWD/vec2.hpp \
    $$PWD/vec3.hpp \
    $$PWD/vec4.hpp \
    $$PWD/vector_relational.hpp

#SOURCES += \
#    $$PWD/detail/glm.cpp



