#pragma once

#include "stdafx.h""
#include "SimplexOps.h"
#include <array>
namespace OptLib  // ����� ��� �������� "������ �����"
{
	template <size_t dim>//dim -��������
	using Point = std::array <double, dim>;//��������� ������� �������� ������ � ������� 8 ���� 
	// ����� ��� ��������� ��� ���� ����� ����� ���� ��������� ��� ������� Point<7> p; - ����� � 7-�� ������ ������������


	template <size_t dim>                                                  // �������� ������ ����� �����, ������ ���� ����� , ����������� ������, ����������� ������ 
	//��������
	Point<dim> operator + (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::plus<>{});
		return result;
	}
	
	//��������
	// ���������
	template <size_t dim>
	Point<dim> operator - (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::minus<>{});
		return result;
	}																																//��������

	template <size_t dim>
	Point<dim> operator * (const Point<dim>& p1, const Point<dim> p2)
	{
		Point<dim> result;
		
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});
		
		return result;
	}

	//�������
	template <size_t dim>
	Point<dim> operator / (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;

		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), SimplexOps::BinaryOps::del<>{});

		return result;
	}

	//��������� ���������
	template <size_t dim>
	double sc (const Point<dim>& p1, const Point<dim>& p2)															//������������� ��������� ������������
	{
		Point<dim> result;
		double res = 0;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});
		for (auto& el : result)
			res += el;
		return res;
	}
	
	/*��������� �� �����*/
	template <size_t dim>
	Point<dim> operator * (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::mult<double>{scalar});
		return result;
	}
	template <size_t dim>
	Point<dim> operator * ( double scalar,const Point<dim>& p1 )
	{
		return operator *(p1,scalar);
	}

	//������� ����� �� ����� � �� ������
	template <size_t dim>
	Point<dim> operator / (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::del<double>{scalar});
		return result;
	}
	template <size_t dim>					//�������� ������ ��������� �����
	Point<dim> operator / (double scalar, const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::del1<double>{scalar});
		return result;
	}


	//�������� ����� � �����
	template <size_t dim>
	Point<dim> operator + (const Point<dim>& p1,double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::plus<double>{scalar});
		return result;
	}
	template <size_t dim>
	Point<dim> operator + ( double scalar, const Point<dim>& p1)
	{
		return operator +(p1, scalar);	
	}


	//��������� ����� � �����
	template <size_t dim>
	Point<dim> operator - (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::minus<double>{scalar});
		return result;
	}
	template <size_t dim>														
	Point<dim> operator - (double scalar, const Point<dim>& p1)
	{
		Point<dim> res = operator*(p1, -1);
		return operator +(res, scalar);
	}

	//������
	template <size_t dim>
	Point<dim>  Abs(const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::Abs<>{});
		return result;
	}
	
	/*������*/
	template <size_t dim>
	Point<dim>  Sqrt(const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::Sqrt<>{});
		return result;
	}
}



//16.02
template <size_t dim>
struct PawPoint
{
	RawPoint() = default;
	point<dim> P;
	RawPoint(const Point<dim>& p) :p{ p }{}
	RawPoint(Point<dim>&& p) :p{ std::move(p)}{};
	RawPoint(const RawPoint<dim>& p) :p{ p } {};
	double operator [](size_t i)const
	{
		return P[i];
	}
	operator Point<dim>()
	{
		return P;
	};
};
template <size_t dim>
struct PointVal :public RawPoint<dim>
{
	double val;
	PointVal() = default;
	//PointVal(const PointVal& p) = default;
	PointVal(Point<dim>&& p, double val) :RawPoint<dim>{ std::move(p) }, val{ val }{};
	PointVal(const Point<dim>& p, double val) :RawPoint<dim>{ p }, val{ val }{};

	bool operator<(const Point<dim>& rhs)
	{return this->val < rhs.val;}
};



//����� � ����� ��������



/*
sqrt		����� ��������
abs			����� ��������
���������	��������
p1*p1		��������
p1+p2		��������
p1+bouble	��������
p1-p2		��������
p1/double	��������
p1/p2		
p1*double	 ��������





*/	
		






//*-/ ��������� �� ����� ������� �� �����






//���� �� ��� �����
/*
class Point
{
Point<dim> operator +(const Point&p1,const Point&p2);
����� ��� �������� ��������
}
*/



// �� ��� ��������� ������ ���� � ������
/*

���������� ��������� ������ � ����� � ������ ����� �����
� ������ ���������� ���������� 
� ��� �������� 
*/