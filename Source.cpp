#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.14159265

/*����� ���������� ���������*/
class sine_wawe_generator
{
private:
	double current_time, time_step, amplitude, frequency, y_result, phase;//����������

public:
	/*�����������*/
	sine_wawe_generator(double current_time = 0.0, double time_step = PI / 50,
		double amplitude = 2.0, double frequency = 1.0, double phase = 0.0)
	{
		this->current_time = current_time;
		this->time_step = time_step;

		this->amplitude = amplitude;
		this->frequency = frequency;
		this->phase = phase;

		this->y_result = this->amplitude * std::sin(2.0 * PI * this->frequency * this->current_time + this->phase);//��������� ���������� �������
	}

	/*����������*/
	~sine_wawe_generator() {

	};

	/*������ ��� ��������� �������� ����������*/
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

	/*������ ��� ��������� �������� ����������*/
	const double get_y_result()
	{
		return this->y_result;
	}

	const double get_current_time()
	{
		return this->current_time;
	}

	/*������-��������*/
	void perform_step()//����� ��� �������� �������� ������� � ���������� ������� � ���������� ��������� ������� �� ������������ ���
	{
		this->y_result = this->amplitude * std::sin(2.0 * PI * this->frequency * this->current_time + this->phase);
		this->set_current_time(this->current_time + this->time_step);
	}

	void reset_generator(sine_wawe_generator* generator)//����� ��� ������ ���������� ������ � ���������� �� ��������� � ������������
	{
		delete generator;
		generator = new sine_wawe_generator();
	}

	void cout_current_state()//����� ��� ������ �������� ������� � ���������� �������
	{
		std::cout << "y(" << this->get_current_time() - this->time_step << ") = " << this->get_y_result() << std::endl;
	}

	void start_generation(double start_time, double end_time)//����� ��� ������� ��������� ��������� � ��������� ��������� �������
	{
		if (start_time >= end_time)
		{
			std::cout << "Cannot start generation : end_time < start_time" << std::endl;
			return;
		}

		this->current_time = start_time;


		while (this->current_time <= end_time)//������� ������� �������� ������� �� ����� �������� � �������� �������� ������� �� ������ ���� �������
		{
			this->perform_step();
			this->cout_current_state();
		}
	}

	void start_generation(double generation_time)//������������� ����� ��� ������� ��������� ��������� � ���������� ������������ ������� ���������
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
	sine_wawe_generator* generator = new sine_wawe_generator();//������� ��������� ������

	std::cout << std::setprecision(10) << std::fixed;//�������� ����� ��� ������

	generator->start_generation(0.0, 10.0);//������ ��������� ���������
	generator->reset_generator(generator);//����� �������� ���������� �� ��������� � ������������

	delete generator;//������� ���������

	std::cout << std::endl;

	//������������� �������������� ������ ���������(��������� ���������� � ����������� ������ ����)
	/*generator->set_current_time(0.0);
	generator->start_generation(10.0);
	generator->reset_generator(generator);*/

	return 0;
}