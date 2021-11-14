#include <iostream>

class jk_trigger
{
private:

	/*�������� �������� ��� ������ ��������*/

	bool clock_values[20] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
	bool j_values[20] = { 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1 };
	bool k_values[20] = { 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 };
	bool preset_values[40] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0 };
	bool clear_values[40] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 };

	bool j, k, clock, preset, clear, q, q_inverted, q_plus_1, q_plus_1_inverted;

	/*������ ��� ��������� ���������� ������*/

	const void set_j(bool j)
	{
		this->j = j;
	}

	const void set_k(bool k)
	{
		this->k = k;
	}

	const void set_clock_value(bool clock)
	{
		this->clock = clock;
	}

	const void set_preset_value(bool preset)
	{
		this->preset = preset;
	}

	const void set_clear_value(bool clear)
	{
		this->clear = clear;
	}

	const void change_q_value()//����� ��� ��������� �������� ������ �������� �� ���������������
	{
		this->q = this->q_plus_1;
		this->q_inverted = this->q_plus_1_inverted;

		this->q_plus_1 = !this->q;
		this->q_plus_1_inverted = !this->q_inverted;
	}

	const void set_q(bool q)
	{
		this->q = this->q_plus_1;
		this->q_inverted = !this->q_plus_1;

		this->q_plus_1 = q;
		this->q_plus_1_inverted = !q;
	}

public:
	/*�����������*/
	jk_trigger(bool j = 0, bool k = 0, bool clock = 0, bool preset = 0, bool clear = 0, bool q = 0)
	{
		this->set_j(j);
		this->set_k(k);
		this->set_clock_value(clock);
		this->set_preset_value(preset);
		this->set_clear_value(clear);

		this->q = q;
		this->q_inverted = !q;

		this->q_plus_1 = q;
		this->q_plus_1_inverted = this->q_inverted;
	}

	/*����������*/
	~jk_trigger() {

	};

	/*������ ��� ��������� ���������� ������*/
	bool const get_j()
	{
		return this->j;
	}

	bool const get_k()
	{
		return this->k;
	}

	bool const get_clock_value()
	{
		return this->clock;
	}

	bool const get_preset_value()
	{
		return this->preset;
	}

	bool const get_clear_value()
	{
		return this->clear;
	}

	bool const get_q_value()
	{
		return this->q;
	}

	bool const get_q_inverted_value()
	{
		return this->q_inverted;
	}

	/*������-��������*/

	void cout_trigger_state()//����� ��������� �������� �� ������ ��������� ����� �������� �� �������� �����, �������� �������� ������ � ��������� ��������� ������ ��������
	{
		std::cout << "Clock : " << this->clock << "; J : " << this->j << "; K : " << this->k
			<< "; PRESET : " << this->preset << "; CLEAR : " << this->clear
			<< "; Q : " << this->q << "; Q+1 : " << this->q_plus_1 << std::endl;
	}

	void check_trigger_state(bool clock_interval)//�������� �� �������� ������� � ��������� ������ �������� �� ��������� ��������� �������
	{
		if (!this->preset && this->clear)//���� �������� 0 �� : ����������� ������������� � 1 �� : ����������� ������
			this->set_q(false);
		else
			if (this->preset && !this->clear)//���� �������� 1 �� : ����������� ������������� � 0 ��: ����������� ������
				this->set_q(true);
			else
				if (this->preset && this->clear)//���� �������� 1 �� : ����������� ������������� � ����������� ������
					return;
				else//���� �������� 0 �� : ����������� ������������� � 0 �� : ����������� ������
				{
					if (clock_interval && this->clock)//���� ��������� ������������ � �������� ������������ ���������� � 0 �� 1
					{
						if (!j && k)//���� �������� 0 �� : ����� J � 1 �� : ����� K
							this->set_q(false);
						else
							if (j && !k)//���� �������� 1 �� : ����� J � 0 �� : ����� K
								this->set_q(true);
							else
								if (!j && !k)//���� �������� 1 �� : ����� J � 1 �� : ����� K - ��������� ������������ (������� �������������� � �������)
									return;
								else//���� �������� 1 �� : ����� J � 1 �� : ����� K
									this->change_q_value();//�������� �������� ������ �������� �� ��������� ��������� ������� �� ���������������
					}
				}
	}

	void start_test()//����� ��� ������� ����� ��������
	{
		int j_k_clock_iterator = 0;//�������� ��� ������������
		bool clock_interval;//������������� � ���������� � ��������� ������������

		for (int i = 0; i < sizeof(this->preset_values); i++)//������ �� ���� ���������, ����������� �� ����������� ����� �������� (��������� ���������� �� ������������)
		{
			clock_interval = false;

			this->preset = this->preset_values[i];//��������� �������� ������ �� �����
			this->clear = this->clear_values[i];

			if (i % 2 == 0)
			{
				this->j = this->j_values[j_k_clock_iterator];//��������� �������� ������ �� �����
				this->k = this->k_values[j_k_clock_iterator];
				this->clock = this->clock_values[j_k_clock_iterator];

				clock_interval = true;//�������� ������������ (����� ��������� ��������� ����� � ������ J � K)

				j_k_clock_iterator++;
			}

			this->check_trigger_state(clock_interval);//�������� �� �������� ������� � ��������� ������ �������� �� ��������� ��������� �������

			this->cout_trigger_state();//����� ��������� �������� �� ������ ��������� ����� �������� �� �������� �����, �������� �������� ������ � ��������� ��������� ������ ��������
		}
	}
};


int main()
{
	jk_trigger* trigger = new jk_trigger();//������� ��������� ������
	trigger->start_test();//������ ����� ��������

	std::cout << std::endl;

	delete trigger;//������� ���������

	return 0;
}