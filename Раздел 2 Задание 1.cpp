#include <iostream>

class jk_trigger
{
private:

	/*ТЕСТОВЫЕ ЗНАЧЕНИЯ ДЛЯ ВХОДОВ ТРИГГЕРА*/

	bool clock_values[20] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
	bool j_values[20] = { 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1 };
	bool k_values[20] = { 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 };
	bool preset_values[40] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0 };
	bool clear_values[40] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 };

	bool j, k, clock, preset, clear, q, q_inverted, q_plus_1, q_plus_1_inverted;

	/*МЕТОДЫ ДЛЯ УСТАНОВКИ ПАРАМЕТРОВ КЛАССА*/

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

	const void change_q_value()//метод для изменения значения выхода триггера на противоположное
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
	/*КОНСТРУКТОР*/
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

	/*ДЕСТРУКТОР*/
	~jk_trigger() {

	};

	/*МЕТОДЫ ДЛЯ ПОЛУЧЕНИЯ ПАРАМЕТРОВ КЛАССА*/
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

	/*МЕТОДЫ-ДЕЙСТВИЯ*/

	void cout_trigger_state()//вывод состояния триггера на момент получения новых сигналов на входящие порты, значения входящих портов и следующее состояние выхода триггера
	{
		std::cout << "Clock : " << this->clock << "; J : " << this->j << "; K : " << this->k
			<< "; PRESET : " << this->preset << "; CLEAR : " << this->clear
			<< "; Q : " << this->q << "; Q+1 : " << this->q_plus_1 << std::endl;
	}

	void check_trigger_state(bool clock_interval)//проверка на принятие решения о состоянии выхода триггера на следующем временном отрезке
	{
		if (!this->preset && this->clear)//если значение 0 на : асинхронной предустановке и 1 на : асинхронном сбросе
			this->set_q(false);
		else
			if (this->preset && !this->clear)//если значение 1 на : асинхронной предустановке и 0 на: асинхронном сбросе
				this->set_q(true);
			else
				if (this->preset && this->clear)//если значение 1 на : асинхронной предустановке и асинхронном сбросе
					return;
				else//если значение 0 на : асинхронной предустановке и 0 на : асинхронном сбросе
				{
					if (clock_interval && this->clock)//если произошло тактирование и значение тактирования изменилось с 0 на 1
					{
						if (!j && k)//если значение 0 на : входе J и 1 на : входе K
							this->set_q(false);
						else
							if (j && !k)//если значение 1 на : входе J и 0 на : входе K
								this->set_q(true);
							else
								if (!j && !k)//если значение 1 на : входе J и 1 на : входе K - состояние невалидности (триггер незадействован в системе)
									return;
								else//если значение 1 на : входе J и 1 на : входе K
									this->change_q_value();//изменяем значение выхода триггера на следующем временном отрезке на противоположное
					}
				}
	}

	void start_test()//метод для запуска теста триггера
	{
		int j_k_clock_iterator = 0;//итератор для тактирования
		bool clock_interval;//подтверждение о нахождении в интервале тактирования

		for (int i = 0; i < sizeof(this->preset_values); i++)//проход по всем значениям, поступающим на асинхронные входы триггера (поступают независимо от тактирования)
		{
			clock_interval = false;

			this->preset = this->preset_values[i];//присвоить значения данным из теста
			this->clear = this->clear_values[i];

			if (i % 2 == 0)
			{
				this->j = this->j_values[j_k_clock_iterator];//присвоить значения данным из теста
				this->k = this->k_values[j_k_clock_iterator];
				this->clock = this->clock_values[j_k_clock_iterator];

				clock_interval = true;//интервал тактирования (можно проверить состояние такта и входов J и K)

				j_k_clock_iterator++;
			}

			this->check_trigger_state(clock_interval);//проверка на принятие решения о состоянии выхода триггера на следующем временном отрезке

			this->cout_trigger_state();//вывод состояния триггера на момент получения новых сигналов на входящие порты, значения входящих портов и следующее состояние выхода триггера
		}
	}
};


int main()
{
	jk_trigger* trigger = new jk_trigger();//создать экземпляр класса
	trigger->start_test();//запуск теста триггера

	std::cout << std::endl;

	delete trigger;//удалить экземпляр

	return 0;
}
