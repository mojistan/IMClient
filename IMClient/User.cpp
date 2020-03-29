#include "User.h"
User::User(const char* tid, const char* tpassword, const char* tnickname)
{
	id = new char[strlen(tid) + 1];
	password = new char[strlen(tpassword) + 1];
	nickname = new char[strlen(tnickname) + 1];
	memcpy(id, tid, strlen(tid) + 1);										//Ӧ�ü�鳤��
	memcpy(password, tpassword, strlen(tpassword) + 1);
	memcpy(nickname, tnickname, strlen(tnickname) + 1);
}

User::User(const char* tid, const char* tpassword)       //ֻ�����û�������
{
	id = new char[strlen(tid) + 1];
	password = new char[strlen(tpassword) + 1];
	memcpy(id, tid, strlen(tid) + 1);										//Ӧ�ü�鳤��
	memcpy(password, tpassword, strlen(tpassword) + 1);
}
User::~User()
{
	if (id != NULL)
	{
		delete[] id;
		id = NULL;
	}
	if (password != NULL)
	{
		delete[] password;
		password = NULL;
	}
	if (nickname != NULL)
	{
		delete[] nickname;
		nickname = NULL;
	}
}
const char* User::getId()
{
	return id;
}
const char* User::getPassword()
{
	return password;
}
const char* User::getNickname()
{
	return nickname;
}
void User::setNickname(const char* name, int len)
{
	nickname = new char[strlen(name)+1];
	memcpy(nickname, name, strlen(name) + 1);
}
