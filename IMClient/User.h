#pragma once
#include"string.h"
class  User
{
private:
	char* id;
	char* password;
	char* nickname;
public:
	User(const char* tid, const char* tpassword, const char* tnickname);

	User(const char* tid, const char* tpassword);      //ֻ�����û�������

	const char* getId();
	const char* getPassword();
	const char* getNickname();
	void setNickname(const char* name,int len);
};
