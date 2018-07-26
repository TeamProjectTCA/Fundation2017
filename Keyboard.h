#pragma once
#include "Base.h"
#include <unordered_map>
#include <string>
#include <vector>

PTR( Keyboard );

class Keyboard : public Base {
public:
	static KeyboardPtr getTask( );
	static std::string getTag( ) { return "KEYBOARD"; }

public:
	Keyboard( );
	virtual ~Keyboard( );

public:
	void initialize( );
	void finalize( );
	void update( );

public:
	int getKeyState( std::string key ) const;
	std::string getString( ) const;
	bool getKeyUp( std::string key ) const;
	bool getKeyDown( std::string key ) const;

private:
	// キー検索。見つかった場合変換後の文字が第二引数に代入される
	bool isExistKeyCode( std::string find_key, std::string &conv_str ) const;

private:
	static const int KEY_MAX = 256;
	int _key_state[ KEY_MAX ];
	std::unordered_map< std::string, int > _key_code;
	std::vector< int > _key_up;
};

