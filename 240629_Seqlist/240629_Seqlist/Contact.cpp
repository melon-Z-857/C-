#include"Seqlist.h"
#include"Contact.h"

int FindByName(contact* con, char name[]) {
	for (int i = 0; i < con->size; i++) {
		if ((strcmp(name, con->arr[i].name)) == 0) {
			return i;
		}
	}
	return -1;
}

void InitContact(contact* con) {
	SLInit(con);
}

void DestroyContact(contact* con) {
	assert(con->arr != NULL);
	free(con->arr);
	con->arr = NULL;
	con->size = 0;
	con->capacity = 0;
}

void AddContact(contact* con) {
	SLCheckCapacity(con);
	printf("请输入联系人姓名 性别 年龄 电话 住址(每输入完一项按回车确定):\n");
	PeoInfo tmp = { 0 };
	scanf("%s", tmp.name);
	scanf("%s", tmp.gender);
	scanf("%d", &tmp.age);
	scanf("%s", tmp.tel);
	scanf("%s", tmp.addr);
	con->arr[con->size] = tmp;
	con->size++;
}

void FindContact(contact* con) {
	printf("请输入需要查找的联系人姓名\n");
	char name[NAME_MAX];
	scanf("%s", name);
	if (FindByName(con, name) < 0) {
		printf("查找的联系人不存在\n");
	}
	else {
		printf("姓名：%s 性别：%s 年龄：%d 电话：%s 住址：%s\n",
			con->arr[FindByName(con, name)].name,
			con->arr[FindByName(con, name)].gender,
			con->arr[FindByName(con, name)].age,
			con->arr[FindByName(con, name)].tel,
			con->arr[FindByName(con, name)].addr);
	}
}

void DelContact(contact* con) {
	printf("请输入需要删除的联系人姓名\n");
	char name[NAME_MAX];
	scanf("%s", name);
	if (FindByName(con, name) < 0) {
		printf("要删除的联系人不存在\n");
	}
	else {
		SLErase(con, FindByName(con, name));
		printf("已成功删除联系人\n");
	}
}

void ModifyContact(contact* con) {
	printf("请输入需要修改的联系人姓名\n");
	char name[NAME_MAX];
	scanf("%s", name);
	if (FindByName(con, name) < 0) {
		printf("要修改的联系人不存在\n");
	}
	else {
		printf("请输入修改后联系人姓名 性别 年龄 电话 住址(每输入完一项按回车确定):\n");
		PeoInfo tmp;
		scanf("%s", tmp.name);
		scanf("%s", tmp.gender);
		scanf("%d", &tmp.age);
		scanf("%s", tmp.tel);
		scanf("%s", tmp.addr);
		con->arr[FindByName(con, name)] = tmp;
		printf("修改成功\n");
	}
}

void ShowContact(contact* con) {
	printf("------------通讯录------------\n");
	for (int i = 0; i < con->size; i++) {
		printf("姓名：%s 性别：%s 年龄：%d 电话：%s 住址：%s\n",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}
	printf("------------------------------\n");
}