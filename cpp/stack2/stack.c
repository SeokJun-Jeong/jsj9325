
int stack[100];
int tos;    //top of stack


void push(int data)	//함수정의
{
	stack[tos] = data;
	++tos; 	//tos = tos+1;
}

int pop(void)  //re가 int기 때문에
{
	--tos;
	return stack[tos];
}