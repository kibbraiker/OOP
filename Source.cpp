#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.14159265

/*КЛАСС ГЕНЕРАТОРА СИНУСОИДЫ*/
class sine_wawe_generator
{
private:
	double current_time, time_step, amplitude, frequency, y_result, phase;//переменные

public:
	/*КОНСТРУКТОР*/
	sine_wawe_generator(double current_time = 0.0, double time_step = PI / 50,
		double amplitude = 2.0, double frequency = 1.0, double phase = 0.0)
	{
		this->current_time = current_time;
		this->time_step = time_step;

		this->amplitude = amplitude;
		this->frequency = frequency;
		this->phase = phase;

		this->y_result = this->amplitude * std::sin(2.0 * PI * this->frequency * this->current_time + this->phase);//результат вычисления функции
	}

	/*ДЕСТРУКТОР*/
	~sine_wawe_generator() {

	};

	/*МЕТОДЫ ДЛЯ УСТАНОВКИ ЗНАЧЕНИЙ ПЕРЕМЕННЫХ*/
	void const set_amplitude(double amplitude)
	{
		this->amplitude = amplitude;
	}

	void const set_frequency(double frequency)
	{
		this->frequency = frequency;
	}

	void const set_time_step(double time_step)
	{
		this->time_step = time_step;
	}

	void const set_current_time(double current_time)
	{
		this->current_time = current_time;
	}

	/*МЕТОДЫ ДЛЯ ПОЛУЧЕНИЯ ЗНАЧЕНИЙ ПЕРЕМЕННЫХ*/
	const double get_y_result()
	{
		return this->y_result;
	}

	const double get_current_time()
	{
		return this->current_time;
	}

	/*МЕТОДЫ-ДЕЙСТВИЯ*/
	void perform_step()//метод для подсчета значения функции с параметром времени и увеличения параметра времени на определенный шаг
	{
		this->y_result = this->amplitude * std::sin(2.0 * PI * this->frequency * this->current_time + this->phase);
		this->set_current_time(this->current_time + this->time_step);
	}

	void reset_generator(sine_wawe_generator* generator)//метод для сброса параметров класса к параметрам по умолчанию в конструкторе
	{
		delete generator;
		generator = new sine_wawe_generator();
	}

	void cout_current_state()//метод для вывода значения функции с параметром времени
	{
		std::cout << "y(" << this->get_current_time() - this->time_step << ") = " << this->get_y_result() << std::endl;
	}

	void start_generation(double start_time, double end_time)//метод для запуска генерации синусоиды с границами параметра времени
	{
		if (start_time >= end_time)
		{
			std::cout << "Cannot start generation : end_time < start_time" << std::endl;
			return;
		}

		this->current_time = start_time;


		while (this->current_time <= end_time)//процесс прохода значений времени по своим границам и подсчета значения функции на каждом шагу времени
		{
			this->perform_step();
			this->cout_current_state();
		}
	}

	void start_generation(double generation_time)//перегруженный метод для запуска генерации синусоиды с установкой длительности времени генерации
	{
		double start_time = this->current_time;
		while (this->current_time <= start_time + generation_time)
		{
			this->perform_step();
			this->cout_current_state();
		}
	}
};

int main()
{
	sine_wawe_generator* generator = new sine_wawe_generator();//создать экземпляр класса

	std::cout << std::setprecision(10) << std::fixed;//точность числа при выводе

	generator->start_generation(0.0, 10.0);//запуск генерации синусоиды
	generator->reset_generator(generator);//сброс значений генератора по умолчанию в конструкторе

	delete generator;//удалить экземпляр

	std::cout << std::endl;

	//ИСПОЛЬЗОВАНИЕ ПЕРЕГРУЖЕННОГО МЕТОДА ГЕНЕРАЦИИ(РЕЗУЛЬТАТ ОДИНАКОВЫЙ С РЕЗУЛЬТАТОМ МЕТОДА ВЫШЕ)
	/*generator->set_current_time(0.0);
	generator->start_generation(10.0);
	generator->reset_generator(generator);*/

	return 0;
}