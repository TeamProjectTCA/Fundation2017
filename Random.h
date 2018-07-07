#pragma once
#include "smart_ptr.h"
#include "Base.h"
#include <vector>
#include <string>

PTR( Random );

/*

�@�����Z���k�E�c�C�X�^���g�p

*/

class Random : public Base {
public:
	static RandomPtr getTask( );
	static std::string getTag( );

public:
	Random( );
	virtual ~Random( );

public:
	void initialize( );
	void update( );

public:
	void setIgnore( unsigned long ignore );
	void setIgnore( double ignore );
	void resetIgnore( );

public:
	// 32�r�b�g������ 0x0�ȏ�0xffffffff�ȉ�
	unsigned long getInt32( ) const;
	unsigned long getInt32( unsigned long range_min, unsigned long range_max ) const;
	// 31�r�b�g������ 0x0�ȏ�0x7fffffff�ȉ�
	long getInt31( ) const;
	
	// ��l������(32�r�b�g���x) 0�ȏ�1�ȉ�
	double getRealOne( ) const;

	// ��l������(32�r�b�g���x) 0�ȏ�1����
	double getRealTwo( ) const;

	// ��l������(32�r�b�g���x) 0���傫��1����
	double getRealThree( ) const;

	// ��l������(53�r�b�g���x) 0�ȏ�1����
	double getRes53( ) const;

private:
	bool isReplay( unsigned long num ) const;
	bool isReplay( double num ) const;

private:
	std::vector< unsigned long > _ignore_long;
	std::vector< double > _ignore_double;
};

