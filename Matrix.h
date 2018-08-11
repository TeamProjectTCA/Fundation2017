#pragma once
#include "Vector.h"

struct Matrix {
	double matrix[ 3 ][ 3 ];

	Matrix( ) {
		// �P�ʍs��𐶐�
		for ( int i = 0; i < 3; i++ ) {
			for ( int j = 0; j < 3; j++ ) {
				matrix[ i ][ j ] = 0;
			}
		}

		for ( int i = 0; i < 3; i++ ) {
			matrix[ i ][ i ] = 1;
		}
	}

	~Matrix( ) {
	}

	// ���h���Q�X�̉�]����(�C�ӎ��̉�]�s��𐶐�)
	inline static Matrix makeTransformRotation( const Vector &in_axis, double radian ) {
		Vector axis = in_axis.normalize( );
		double value = ( 1 - cos( radian ) );
		double value_sin = sin( radian );
		double value_cos = cos( radian );

		Matrix mat;
		mat.matrix[ 0 ][ 0 ] = value_cos + axis.x * axis.x * value;
		mat.matrix[ 0 ][ 1 ] = axis.x * axis.y * value - axis.z * value_sin;
		mat.matrix[ 0 ][ 2 ] = axis.z * axis.x * value + axis.y * value_sin;

		mat.matrix[ 1 ][ 0 ] = axis.x * axis.y * value + axis.z * value_sin;
		mat.matrix[ 1 ][ 1 ] = value_cos + axis.y * axis.y * value;
		mat.matrix[ 1 ][ 2 ] = axis.y * axis.z * value - axis.x * value_sin;

		mat.matrix[ 2 ][ 0 ] = axis.z * axis.x * value - axis.y * value_sin;
		mat.matrix[ 2 ][ 1 ] = axis.y * axis.z * value + axis.x * value_sin;
		mat.matrix[ 2 ][ 2 ] = value_cos + axis.z * axis.z * value;

		return mat;
	}

	inline Vector multiply( const Vector &in_vec ) const {
		Vector result;
		result.x = in_vec.x * matrix[ 0 ][ 0 ] + in_vec.y * matrix[ 0 ][ 1 ] + in_vec.z * matrix[ 0 ][ 2 ];
		result.y = in_vec.x * matrix[ 1 ][ 0 ] + in_vec.y * matrix[ 1 ][ 1 ] + in_vec.z * matrix[ 1 ][ 2 ];
		result.z = in_vec.x * matrix[ 2 ][ 0 ] + in_vec.y * matrix[ 2 ][ 1 ] + in_vec.z * matrix[ 2 ][ 2 ];
		return result;
	}
};