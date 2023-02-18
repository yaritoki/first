#pragma once

#include "stdafx.h""
#include "SimplexOps.h"
#include <array>
namespace OptLib  // далее идЄт описание "класса ѕоинт"
{
	template <size_t dim>//dim -параметр
	using Point = std::array <double, dim>;//контейнер верктор зн€т€тс€ доублы с пам€тью 8 байт 
	// поинт это псевданим дл€ того чтобы можно было сокращать код применр Point<7> p; - точка в 7-ми мерном пространстве


	template <size_t dim>                                                  // дописать вектор минус цисло, вектор плюс число , поэлементно модуль, поэлементно корень 
	//сложение
	Point<dim> operator + (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::plus<>{});
		return result;
	}
	
	//работает
	// вычитание
	template <size_t dim>
	Point<dim> operator - (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::minus<>{});
		return result;
	}																																//работает

	template <size_t dim>
	Point<dim> operator * (const Point<dim>& p1, const Point<dim> p2)
	{
		Point<dim> result;
		
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});
		
		return result;
	}

	//деление
	template <size_t dim>
	Point<dim> operator / (const Point<dim>& p1, const Point<dim>& p2)
	{
		Point<dim> result;

		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), SimplexOps::BinaryOps::del<>{});

		return result;
	}

	//умножение скал€рное
	template <size_t dim>
	double sc (const Point<dim>& p1, const Point<dim>& p2)															//переименовать скал€рное произведение
	{
		Point<dim> result;
		double res = 0;
		std::transform(p1.begin(), p1.end(), p2.begin(), result.begin(), std::multiplies<>{});
		for (auto& el : result)
			res += el;
		return res;
	}
	
	/*умножение на число*/
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

	//деление точки на число и на оборот
	template <size_t dim>
	Point<dim> operator / (const Point<dim>& p1, double scalar)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::del<double>{scalar});
		return result;
	}
	template <size_t dim>					//пришлось писать отдельный пункт
	Point<dim> operator / (double scalar, const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::del1<double>{scalar});
		return result;
	}


	//сложение числа и точки
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


	//вычитание числа и точки
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

	//модуль
	template <size_t dim>
	Point<dim>  Abs(const Point<dim>& p1)
	{
		Point<dim> result;
		std::transform(p1.begin(), p1.end(), result.begin(), SimplexOps::UnaryOps::Abs<>{});
		return result;
	}
	
	/*корень*/
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



//вывод в поток работает



/*
sqrt		почтм работает
abs			почти работает
скал€рное	работает
p1*p1		работает
p1+p2		работает
p1+bouble	работает
p1-p2		работает
p1/double	работает
p1/p2		
p1*double	 работает





*/	
		






//*-/ умножение на число деление на число






//если бы был класс
/*
class Point
{
Point<dim> operator +(const Point&p1,const Point&p2);
далее идЄт алгоритм сложение
}
*/



// всЄ что шаблонное должно быть в хедере
/*

перегрузка оператора вывода в поток в другом файле нужно
в поинте реализаци€ операторов 
в спп алгоритм 
*/