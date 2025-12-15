#include"代码声明.h"

string yhm, mima;

void zhucaidan()//主菜单
{
	
	cout << "==—— 主 菜 单 ——== "<< endl;
	cout << " 用户登录【1】" << endl;
	cout << " 用户注册【2】" << endl;
	cout << " 管理员登录【3】" << endl;
	cout << " 退出程序【任意键】" << endl;
	cout << "请选择操作：";
	int dlu;
	cin >> dlu;
		if (dlu == 1)
		{
			system("cls");
			denglu();
		}
		else if (dlu == 2)
		{
			system("cls");
			zhuce();
		}
		else if (dlu == 3)
		{
			system("cls");
			GLdenlu();
		}
		else
		{
			cout << "已退出该程序" << endl;

			exit(0);
		}
	
	
}

void guanriDL()//管理员功能主菜单
{
	int cz;
	cout << "==—— 管理员功能 ——== " << endl;
	cout << " 查询用户账号【1】" << endl;
	cout << " 删除用户账号【2】" << endl;
	cout << " 修改用户密码【3】" << endl;
	cout << " 退出管理员登录【4】" << endl;
	cout << "请选择操作：" << endl;
	
	while (true)
	{
	FANHUI11:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			GLchakan();
		}
		else if (cz == 2)
		{
			system("cls");
			GLshangchu();

		}
		else if (cz == 3)
		{
			system("cls");
			GLxiugai();

		}
		else if(cz==4)
		{
			system("cls");
			zhucaidan();
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUI11;
		}
	}
}//管理员功能菜单

void GLxiugai()//修改用户名密码
{

	remove("lingshi.txt");
	string yhmgl, id, mimagl;
	ifstream glchak;
	glchak.open("yonghu.txt");
	cout << "————以下为用户信息列表————" << endl;
	while (glchak >> yhmgl && glchak >> mimagl && glchak >> id)//读取用户信息
	{
		cout << "用户名：" << yhmgl << " " << "密码：" << mimagl<<" "<<"ID:" << id << endl;
	}
	cout << "————以上为用户信息列表————" << endl;
	glchak.close();

	//监测输入ID是否有效
	string lurudaima;
	ifstream glchak5;
	glchak5.open("yonghu.txt");
	while (glchak5 >> yhmgl >> mimagl >> id)
	{
	FANHUI:;
		cout << "请输入你要修改密码的用户ID：" << endl;
		cin >> lurudaima;
		if (lurudaima == id)
		{

			glchak5.close();
			break;
		}
		else
		{
			cout << "无效ID，请重新输入" << endl;
			goto FANHUI;
		}

	}


	//修改用户密码，先进行删除
	ifstream chak("yonghu.txt");
	while (chak >> yhmgl >> mimagl >> id)
	{

		if (id == lurudaima)
		{
			chak.close();

			ifstream in("yonghu.txt");
			ofstream out("lingshi.txt");
			string s;

			while (getline(in, s))
			{
				stringstream ss(s);
				string name, pass, tid;
				ss >> name >> pass >> tid;
				if (tid != lurudaima)
				{
					out << s << '\n';
				}
			}
			

			in.close();
			out.close();
			remove("yonghu.txt");
			rename("lingshi.txt", "yonghu.txt");
			break;

		}
	}
	
	//删除后再写入原来的用户信息，用户名和ID不变，由管理员重新写入新的密码
	string newmima;
	cout << "请输入新的密码" << endl;
	cin >> newmima;
	ofstream GLxiuga;
	GLxiuga.open("yonghu.txt", ios::app);
	GLxiuga << yhmgl << " " << newmima << " " << id << endl;
	GLxiuga.close();


	int cz;
	cout << "按1返回，按2继续修改" << endl;
	while (true)
	{
	FANHUI1:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			guanriDL();

		}
		else if (cz == 2)
		{
			system("cls");
			GLxiugai();

		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUI1;
		}
	}
}

void GLshangchu()//管理员删除用户
{
	remove("lingshi.txt");
	string yhmgl, id, mimagl;
	ifstream glchak;
	
	glchak.open("yonghu.txt");
	
	//对txt文件所有用户信息进行读取
		cout << "————以下为用户信息列表————" << endl;
		while (glchak >> yhmgl && glchak >> mimagl && glchak >> id)
		{

			cout << "用户名：" << yhmgl << " " << " " << "ID:" << id << endl;
		}
		cout << "————以上为用户信息列表————" << endl;
		glchak.close();
		
	
		

	string lurudaima;
	ifstream glchak5;
	glchak5.open("yonghu.txt");
	while (glchak5>>yhmgl>> mimagl>>id)//检测输入的ID是否有效
	{
	FANHUI:;
		cout << "请输入你要删除的用户ID：" << endl;
		cin >> lurudaima;
		if (lurudaima == id)
		{
			
			glchak5.close();
			break;
		}
		else
		{
			cout << "无效ID，请重新输入" << endl;
			goto FANHUI;
		}
	
	}

	//进行用户删除，先读取除了需删除的用户以外的所有用户信息并复制到新建的txt临时文件里面，再删除旧文件，重命名临时文件
	ifstream chak("yonghu.txt");
	while (chak >> yhmgl >> mimagl >> id)
	{
		
		if (id == lurudaima)
		{
			chak.close();

			ifstream in("yonghu.txt");
			ofstream out("lingshi.txt");
			string s;

			while (getline(in, s))
			{
				stringstream ss(s);
				string name, pass, tid;
				ss >> name >> pass >> tid;
				if (tid != lurudaima)
				{
					out << s << '\n';
				}
			}

			in.close();
			out.close();
			remove("yonghu.txt");//删除旧文件
			rename("lingshi.txt", "yonghu.txt");//重命名临时文件
			break;
		}
	}



	

	
	cout << "用户：" << yhmgl << "已被删除" << endl;
	cout << "按1返回,按2继续删除" << endl;
	int cz;
	while (true)
	{
	FANHUI2:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			guanriDL();
			
		}
		else if (cz==2)
		{
			system("cls");
			GLshangchu(); 
			
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUI2;
		}
	}
	
}

void GLdenlu()//检测管理员登录的代码
{
	
	string czgl;
	string daima;
	ifstream gldl;
	gldl.open("guanri.txt");
	cout << "请输入管理员访问代码" << endl;
	cin >> czgl;
	while (gldl >> daima)//对txt文件写入的管理员登录代码进行读取
	{
		if (czgl==daima)//如果读取到则跳转到管理员菜单
		{
			gldl.close();
			system("cls");
			guanriDL();

		}
	
	}
	cout << "登录失败" << endl;
	int cz;
	while (1)
	{
		cout << "按1返回" << endl;
		cin >> cz;
		if(cz == 1)
		{
			system("cls");
			zhucaidan();
			break;
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
		}

	}
	
	
	
}

void GLchakan()//管理员查看所有用户信息
{

	int czgl;
	string yhmgl, id, mimagl;
	ifstream glchak;
	glchak.open("yonghu.txt");
	cout << "————以下为用户信息列表————" << endl;
	while (glchak >> yhmgl && glchak >> mimagl && glchak >> id)//读取并输出所有的用户信息
	{
		cout << "用户名：" << yhmgl << " " << "密码：" << mimagl << " " << "ID:" << id << endl;
	}
	glchak.close();
	
	while (1) 
	{
		cout << "输入1返回：" << endl;
		cin >> czgl;
		if (czgl == 1)
		{
			system("cls");
			guanriDL();
			break;
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
		}
		
	}
	
}

void denglu()//用户进行登录
{
	
	string yhmm;
	string dlyhm, dlmima,dlsuijishu;
	ifstream dl;
	dl.open("yonghu.txt");
	
	cout << "==—— 用户登录 ——== " << endl;
	cout << " 用户名：";
	cin >> yhm;
	cout << " 密码：";
	cin >> mima;
	while (dl >> dlyhm && dl >> dlmima &&dl>> dlsuijishu)//对txt文件进行读取，检测输入的用户与密码是否存在
	{
		if (yhm==dlyhm&&mima==dlmima)//若读取到则跳转到用户菜单
		{
			
			dl.close();
			system("cls");
			YHcaidan();
			
		}
	}
	int cz;
	cout << "登录失败 输入1重新登录" << endl;
	cout << "若没有账号 输入2注册账号" << endl;
	
	while (true)
	{
		cout << "请输入操作：" << endl;
		cin >> cz;
		if (cz==1)
		{
			system("cls");
			denglu();
			break;
		}
		else if(cz==2)
        {
			system("cls");
			zhuce();
			break;
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
		}
	}
	
			
}

void zhuce()//用户进行注册
{
	
	string yhmzc, mimazc,chatyhm,chatmima,id;
	int xz;
	ofstream ofs;
	ifstream chat;
	
	cout << "==—— 用户注册 ——== " << endl;

	while (true) 
	{
		cout << " 请输入用户名：" << endl;
		cin >> yhmzc;

		
		ifstream chat("yonghu.txt");
		if (!chat.is_open()) 
		{
			break;
		}

		
		while (chat >> chatyhm >> chatmima >> id)//检测输入的用户名是否已经存在
		{
			
			
			if (yhmzc == chatyhm) 
			{
				cout << "账号已存在，请重新输入！" << endl;//若存在就让用户重新输入用户名
				chat.close();
				goto REINPUT; 
			}
		}
		chat.close();
		break; 
	REINPUT:;
	}
	
	//生成随机随机数作为用户ID
	srand((unsigned int)time(NULL));
	int suijishu = rand() % 90000 + 10000;

	cout << " 请输入密码：" << endl;
	cin >> mimazc;
	ofs.open("yonghu.txt", ios::app);

	ofs <<yhmzc<<" "<<mimazc<<" "<<suijishu<<endl;//将注册的用户名与密码写入txt文件
	
	ofs.close();
	cout << "注册成功" << endl;
	cout << "按1返回登录" << endl;
	
	while (true)
	{
		
		cin >> xz;
		if (xz==1)
		{
			system("cls");
			zhucaidan();
			break;
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
		}
		
	}
}

void tongji() //用户统计功能
{
	string word1, chayhm1, daima1, month1, day1, year1, leixing1;
	ifstream chak1;
	int arr[6] = { 0,0,0,0,0,0 };
	int drr[9] = { 0,0,0,0,0,0,0,0,0 };
	int m1, m2, m3=0;
	int mm1=0, mm2 = 0, mm3 = 0, mm4 = 0, mm5 = 0;//后面才想起来数组。。。。。。
	chak1.open("shouru.txt");
	cout << "————以下为总收入信息————" << endl;
	//对所有的收入记录进行读取
	while (chak1 >> chayhm1 >> leixing1 >> word1 >> m1 >> year1 >> month1 >> day1 >> daima1)
	{
		if (yhm == chayhm1)//判断用户名
		{
			m3 = m3 + m1;
			arr[0]++;
			if (leixing1=="工资")//对所有类型进行累加，并记录累加的次数
			{
				mm1 = mm1 + m1;
				arr[1]++;
			}
			else if (leixing1 == "奖金")
			{
				mm2 = mm2 + m1;
				arr[2]++;
			}
			else if (leixing1 == "兼职")
			{
				mm3 = mm3 + m1;
				arr[3]++;
			}
			else if (leixing1 == "理财")
			{
				mm4 = mm4 + m1;
				arr[4]++;
			}
			else if (leixing1 == "其它")
			{
				mm5 = mm5 + m1;
				arr[5]++;
			}
		}

	}
	chak1.close();
	cout << "总收入为：" << m3  <<"元"<<"  " <<"共统计" << arr[0]<<"次"<<endl;
	cout << "工资类型总收入为：" << mm1 <<"元"<< "  " << "共统计" << arr[1] << "次" << endl;
	cout << "奖金类型总收入为：" << mm2 <<"元"<< "  " << "共统计" << arr[2] << "次" << endl;
	cout << "兼职类型总收入为：" << mm3 <<"元"<< "  " << "共统计" << arr[3] << "次" << endl;
	cout << "理财类型总收入为：" << mm4 <<"元"<< "  " << "共统计" << arr[4] << "次" << endl;
	cout << "其它类型总收入为：" << mm5 <<"元"<< "  " << "共统计" << arr[5] << "次" << endl;


	string word2, chayhm2, daima2, leixing2, month2, year2, day2;
	ifstream chak2;
	int  m4=0;
	int mmm1 = 0, mmm2 = 0, mmm3 = 0, mmm4 = 0, mmm5 = 0, mmm6 = 0, mmm7 = 0, mmm8 = 0;
	chak2.open("zhichu.txt");
	cout << "————以下为总支出信息————" << endl;
	//对所有的支出记录进行读取
	while (chak2 >> chayhm2 >> leixing2 >> word2 >> m2 >> year2 >> month2 >> day2 >> daima2)
	{
		if (yhm == chayhm2)
		{
			m4 = m4 + m2;
			drr[0]++;
			if (leixing2=="餐饮")//对所有类型进行累加，并记录累加的次数
			{
				mmm1 = mmm1 + m2;
				drr[1]++;
			}
			else if (leixing2 == "购物")
			{
				mmm2 = mmm2 + m2;
				drr[2]++;
			}
			else if (leixing2 == "日用")
			{
				mmm3 = mmm3 + m2;
				drr[3]++;
			}
			else if (leixing2 == "交通")
			{
				mmm4 = mmm4 + m2;
				drr[4]++;
			}
			else if (leixing2 == "娱乐")
			{
				drr[5]++;
				mmm5 = mmm5 + m2;
			}
			else if (leixing2 == "通讯")
			{
				mmm6 = mmm6 + m2;
				drr[6]++;
			}
			else if (leixing2 == "医疗")
			{
				mmm7 = mmm7 + m2;
				drr[7]++;
			}
			else if (leixing2 == "其它")
			{
				mmm8 = mmm8 + m2;
				drr[8]++;
			}
			
		}
	}
	chak2.close();

	cout << "总支出为：" << m4 <<"元"<< "  " << "共统计" << drr[0] << "次" << endl;
	cout << "餐饮类型总支出为：" << mmm1 << "元" << "  " << "共统计" << drr[1] << "次" << endl;
	cout << "购物类型总支出为：" << mmm2 << "元" << "  " << "共统计" << drr[2] << "次" << endl;
	cout << "日用类型总支出为：" << mmm3 << "元" << "  " << "共统计" << drr[3] << "次" << endl;
	cout << "交通类型总支出为：" << mmm4 << "元" << "  " << "共统计" << drr[4] << "次" << endl;
	cout << "娱乐类型总支出为：" << mmm5 << "元" << "  " << "共统计" << drr[5] << "次" << endl;
	cout << "通讯类型总支出为：" << mmm6 << "元" << "  " << "共统计" << drr[6] << "次" << endl;
	cout << "医疗类型总支出为：" << mmm7 << "元" << "  " << "共统计" << drr[7] << "次" << endl;
	cout << "其它类型总支出为：" << mmm8 << "元" << "  " << "共统计" << drr[8] << "次" << endl;
	cout << "-----------------------------------" << endl;
	int m5 = m3 - m4;//进行余额的计算
	cout << endl;
	cout << endl;
	cout << "剩余: " << m5 << " 元" << endl;


	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	int cz;
	cout << "输入1返回" << endl;
	while (true)
	{
	FANHUItongji:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			YHcaidan();

		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUItongji;
		}
	}
}

void YHcaidan()//用户菜单
{
	system("cls");
	cout << "==—— 用 户 菜 单 ——== " << endl;
	cout << " 记账功能【1】" << endl;
	cout << " 统计查询【2】" << endl;
	cout << " 用户注销【3】" << endl;
	cout << "  返 回【4】" << endl;
	cout << "请选择操作：";
	int cz;
	while (true)
	{
	HHH:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			JZgongneng();
		}
		else if (cz == 2)
		{
			system("cls");
			tongji();
		}
		else if (cz == 3)
		{
			system("cls");
			zhuxiao();
		}
		else if (cz == 4)
		{
			system("cls");
			zhucaidan();
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto HHH;
		}
	}


}

void JZgongneng()//记账功能
{
	cout << "==—— 记账功能 ——== " << endl;
	cout << " 添加收入【1】" << endl;
	cout << " 添加支出【2】" << endl;
	cout << " 查看所有记录【3】" << endl;
	cout << " 删除记录【4】" << endl;
	cout << "  返 回【5】" << endl;
	cout << "请选择操作：";
	int cz;

	while (true)
	{
	LLL:;
		cin >> cz;
		if (cz == 6)
		{
			system("cls");
			YHcaidan();
		}
		else if (cz == 1)
		{
			system("cls");
			shouru();
		}
		else if (cz == 2)
		{
			system("cls");
			zhichu();
		}
		else if (cz == 3)
		{
			system("cls");
			chakan();
		}
		else if (cz == 4)
		{
			system("cls");
			shangchu();
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto LLL;
		}
	}
}

void zhuxiao() //用户注销
{
	remove("lingshi.txt");
	remove("lingshi1.txt");
	remove("lingshi2.txt");
	string yhmm;
	string dlyhm, dlmima, dlsuijishu;
	ifstream dl;
	string word1, chayhm1, money1, daima1, month1, day1, year1, leixing1;
	ifstream chak1;
	string word2, chayhm2, money2, daima2, leixing2, month2, year2, day2;
	ifstream chak2;
	string zhuxiaoyhm, zhuxiaomima;

	cout << "==—— 用户注销 ——== " << endl;
	
	cout << "为确保安全，需要重新输入用户名与密码" << endl;
	while (true) //检测输入的用户名与登录的用户名是否一致
	{
	REINPUT22:;
	
		cout << " 请输入用户名：" << endl;
		cin >> zhuxiaoyhm;
    
		   if (zhuxiaoyhm==yhm)
			{
				cout << "用户名正确" << endl;
				break;			
			}
			else
			{
				cout << "用户名错误，请重新输入" << endl;			
				goto REINPUT22;
			}	
		}
	while (true)//检测输入的密码与登录的密码是否一致
	{
	REINPUT23:;
		
		cout << " 请输入密码：" << endl;
		cin >> zhuxiaomima;
			if ( zhuxiaomima ==mima)
			{
				cout << "密码正确" << endl;		
				break;
			
			}
			else
			{			
				cout << "密码错误，请重新输入" << endl;
				goto REINPUT23;
			}			
	}


			
			dl.open("yonghu.txt");
			while (dl >> dlyhm && dl >> dlmima && dl >> dlsuijishu)//对用户txt文件中的用户信息进行删除
			{



				dl.close();
				ofstream out("lingshi.txt");
				ifstream in("yonghu.txt");
				string s;
				while (getline(in, s))
				{
					if (s.find(yhm) == string::npos)
					{
						out << s << '\n';
					}
				}


				in.close();
				out.close();
				remove("yonghu.txt");
				rename("lingshi.txt", "yonghu.txt");
				break;



			}


			chak1.open("shouru.txt");
			while (chak1 >> chayhm1 >> leixing1 >> word1 >> money1 >> year1 >> month1 >> day1 >> daima1)//对收入txt有关的所有收入记录进行删除
			{

			
				
					chak1.close();
					ofstream out("lingshi1.txt");
					ifstream in("shouru.txt");
					string s;
					while (getline(in, s))
					{
						if (s.find(yhm) == string::npos)
						{
							out << s << '\n';
						}
					}


					in.close();
					out.close();
					remove("shouru.txt");
					rename("lingshi1.txt", "shouru.txt");
					break;

				

			}


            chak2.open("zhichu.txt");
			while (chak2 >> chayhm2 >> leixing2 >> word2 >> money2 >> year2 >> month2 >> day2 >> daima2)//对收入txt有关的所有支出记录进行删除
			{
				
				
					chak2.close();
					ofstream out("lingshi2.txt");
					ifstream in("zhichu.txt");
					string s;
					while (getline(in, s))
					{
						if (s.find(yhm) == string::npos)
						{
							out << s << '\n';
						}
					}

					in.close();
					out.close();
					remove("zhichu.txt");
					rename("lingshi2.txt", "zhichu.txt");
					break;

				
			}
	
	cout << "该账户已注销" << endl;
	int cz;
	cout << "输入1返回" << endl;
	while (true)
	{
	FANHUIchakan:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			zhucaidan();

		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUIchakan;
		}
	}


}

void shouru()//用户收入记录
{
    shouru:;
	//对该条记录生成一个随机数ID
	srand((unsigned int)time(NULL));
	int suijishu = rand() % 9000 + 1000;

	time_t now = time(NULL);
	tm* localNow = localtime(&now);
    int year = localNow->tm_year + 1900;
	int month = localNow->tm_mon + 1;
	int day = localNow->tm_mday;
	
	
	string word, money, leixing;

	cout << "==—— 添加收入 ——== " << endl;
	cout << "请输入类型" << endl;
	cout << "1工资，2奖金，3兼职，4理财，5其它" << endl;
	cin >> leixing;
	if (leixing=="1")
	{
		leixing = "工资";
	}
	else if (leixing == "2")
	{
		leixing = "奖金";
	}
	else if (leixing == "3")
	{
		leixing = "兼职";
	}
	else if (leixing == "4")
	{
		leixing = "理财";
	}
	else  
	{
		leixing = "其它";
	}
	
	
	cout << "请输入备注" << endl;
	
	ofstream shouru;
	shouru.open("shouru.txt", ios::app);
	cin >> word;
	cout << "请输入金额（元）" << endl;
	cin >> money;
	shouru << yhm << " " <<leixing <<" " << word << " " << money << " " << year << " " << month << " " << day << " " << suijishu << endl;//将记录写入txt文件
	shouru.close();
	cout << "记账成功" << endl;
	cout << "类型:"<<leixing << " " << "备注:" << word << " " << money << "元"<<" "<< year << "年" << month << "月" << day << "日"  << endl;

	int cz;
	cout << "输入1返回，输入2继续记账" << endl;
	while (true)
	{
	FANHUIshouru:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			JZgongneng();

		}
		else if (cz == 2)
		{
			system("cls");
			goto shouru;
			
		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUIshouru;
		}
	}


}

void zhichu()//对支出进行记录
{

zhichu:;
	//生成一个随机数作为该支出记录的ID
	srand((unsigned int)time(NULL));
	int suijishu = rand() % 9000 + 1000;

	time_t now = time(NULL);
	tm* localNow = localtime(&now);
	int year = localNow->tm_year + 1900;
	int month = localNow->tm_mon + 1;
	int day = localNow->tm_mday;

	string word, money,leixing;
	cout << "==—— 添加支出 ——== " << endl;
	cout << "请输入类型" << endl;
	cout << "1餐饮，2购物，3日用，4交通，5娱乐，6通讯，7医疗，8其它" << endl;
	cin >> leixing;
	if (leixing == "1")
	{
		leixing = "餐饮";
	}
	else if (leixing == "2")
	{
		leixing = "购物";
	}
	else if (leixing == "3")
	{
		leixing = "日用";
	}
	else if (leixing == "4")
	{
		leixing = "交通";
	}
	else if (leixing == "5")
	{
		leixing = "娱乐";
	}
	else if (leixing == "6")
	{
		leixing = "通讯";
	}
	else if (leixing == "7")
	{
		leixing = "医疗";
	}
	else
	{
		leixing = "其它";
	}
	cout << "请输入备注" << endl;
	
	ofstream zhichu;
	zhichu.open("zhichu.txt", ios::app);
	cin >> word;
	cout << "请输入金额(元)" << endl;
	cin >> money;
	zhichu << yhm << " " << leixing << " " << word << " " << money << " " << year << " " << month << " " << day << " " << suijishu << endl;//将记录写入txt文件
	zhichu.close();
	cout << "记账成功" << endl;
	cout << "类型：" << leixing << " " << "备注：" << word << " " << money << "元" << " " << year << "年" << month << "月" << day << "日" << endl;

	int cz;
	cout << "输入1返回，输入2继续记账" << endl;
	while (true)
	{
	FANHUIzhichu:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			JZgongneng();

		}
		else if (cz == 2)
		{
			system("cls");
			goto zhichu;

		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUIzhichu;
		}
	}


	
	
}

void chakan()//用户查看所有支出与收入记录
{
	
	string word1,chayhm1,money1,daima1,month1,day1,year1,leixing1;
	ifstream chak1;
	
	chak1.open("shouru.txt");
	cout << "————以下为收入记录————" << endl;
	while (chak1 >>chayhm1>>leixing1>>word1>> money1>> year1 >>month1>>day1>>daima1)//读取所有收入记录
	{
		if (yhm == chayhm1)
		{//对所有收入记录进行打印
			cout << "类型：" << leixing1 << " " << "备注：" << word1 << " " << money1 << "元" << " " << year1 << "年" << month1 << "月" << day1 << "日" <<endl;

		}
	}
	chak1.close();
	string word2, chayhm2,money2,daima2,leixing2,month2,year2,day2;
	ifstream chak2;
	chak2.open("zhichu.txt");
	cout << "————以下为支出记录————" << endl;
	while (chak2 >> chayhm2 >> leixing2 >> word2 >> money2 >> year2 >> month2 >> day2 >> daima2)//读取所有支出记录
	{
		if (yhm == chayhm2)
		{//对所有的支出记录进行打印
			cout << "类型：" << leixing2 << " " << "备注：" << word2 << " " << money2 << "元" << " " << year2 << "年" << month2 << "月" << day2 << "日"  << endl;

		}
	}
	chak2.close();
	int cz;
	cout << "输入1返回" << endl;
	while (true)
	{
	FANHUIchakan :;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			JZgongneng();

		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUIchakan;
		}
	}
}

void shangchu()//用户删除记账信息
{
    shangchu:;
	remove("lingshi2.txt");
	remove("lingshi1.txt");
	string word1, chayhm1, money1, daima1, month1, day1, year1, leixing1;
	ifstream chak1;
	chak1.open("shouru.txt");
	cout << "————以下为收入记录————" << endl;
	while (chak1 >> chayhm1 >> leixing1 >> word1 >> money1 >> year1 >> month1 >> day1 >> daima1)//对所有的收入记录进行打印
	{
		if (yhm == chayhm1)
		{
			cout << "类型：" << leixing1 << " " << "备注：" << word1 << " " << money1 << "元" << " " << year1 << "年" << month1 << "月" << day1 << "日" << " " << "代码：" << daima1 << endl;

		}
	}
	chak1.close();
	string word2, chayhm2, money2, daima2, leixing2, month2, year2, day2;
	ifstream chak2;
	chak2.open("zhichu.txt");
	cout << "————以下为支出记录————" << endl;
	while (chak2 >> chayhm2 >> leixing2 >> word2 >> money2 >> year2 >> month2 >> day2 >> daima2)//对所有的支出记录进行打印
	{
		if (yhm == chayhm2)
		{
			cout << "类型：" << leixing2 << " " << "备注：" << word2 << " " << money2 << "元" << " " << year2 << "年" << month2 << "月" << day2 << "日" << " " << "代码：" << daima2 << endl;

		}
		
	}
	chak2.close();
	string lurudaima;
	


	while (true)
	{

	FANHUI4:;
		chak1.open("shouru.txt");
		chak2.open("zhichu.txt");

		cout << "请输入你要删除的记录的代码：" << endl;
		cin >> lurudaima;
		//读取输入的代码是否存在
		chak1 >> chayhm1 >> leixing1 >> word1 >> money1 >> year1 >> month1 >> day1 >> daima1;
		chak2 >> chayhm2 >> leixing2 >> word2 >> money2 >> year2 >> month2 >> day2 >> daima2;
		
	
			
			if (lurudaima == daima1)
			{
				cout << "删除成功" << endl;
				chak2.close();
				chak1.close();
				break;
			}
			else if(lurudaima == daima2)
			{
				cout << "删除成功" << endl;
				chak2.close();
				chak1.close();
				break;

			}
			else
			{
				cout << "无效代码，请重新输入" << endl;
				goto FANHUI4;
			}

		

	}
	
	
	
	chak1.open("shouru.txt");
	while (chak1 >> chayhm1 >> leixing1 >> word1 >> money1 >> year1 >> month1 >> day1 >> daima1)//对输入的相关记录进行删除
	{
		
		if (yhm == chayhm1&&daima1==lurudaima)//对应代码寻找要删除的记录
		{
			chak1.close();
			ofstream out("lingshi1.txt");
			ifstream in("shouru.txt");
			string s;
			while (getline(in, s))
			{
				if (s.find(daima1) == string::npos)
				{
					out << s << '\n';
				}
			}


			in.close();
			out.close();
			remove("shouru.txt");
			rename("lingshi1.txt", "shouru.txt");
			break;

		}
		
	}
	
	
	
	
	
	chak2.open("zhichu.txt");
     while (chak2 >> chayhm2 >> leixing2 >> word2 >> money2 >> year2 >> month2 >> day2 >> daima2)//对输入的相关记录进行删除
	{
		if (yhm == chayhm2&&daima2==lurudaima)//对应代码寻找要删除的记录
		{
			chak2.close();
			ofstream out("lingshi2.txt");  
			ifstream in("zhichu.txt");  
			string s;  
			while (getline(in, s))  
			{
				if (s.find(daima2) == string::npos) 
				{
					out << s << '\n';
				}
			}
			
			in.close(); 
			out.close(); 
			remove("zhichu.txt");  
			rename("lingshi2.txt", "zhichu.txt"); 
			break;

		}
	}
	

	int cz;
	cout << "输入1返回，输入2继续删除" << endl;
	while (true)
	{
	FANHUIshangchu:;
		cin >> cz;
		if (cz == 1)
		{
			system("cls");
			JZgongneng();

		}
		else if (cz == 2)
		{
			system("cls");
			goto shangchu;

		}
		else
		{
			cout << "无效操作，请重新输入" << endl;
			goto FANHUIshangchu;
		}
	}

}

int main()
{
	zhucaidan();
	return 0;
	
}