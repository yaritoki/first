#pragma once
#include <functional>
#include <math.h>
namespace OptLib
{
	namespace SimplexOps
	{																					//a+b=b+a
		namespace UnaryOps
		{
			template<class Scalar>
			struct plus
			{
				constexpr
					plus(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs + scalar;
				}
			protected:
				Scalar scalar;
			};

			template<class Scalar>
			struct minus
			{
				constexpr
					minus(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs - scalar;
				}
			protected:
				Scalar scalar;
			};

			template<class Scalar>
			struct mult
			{
				constexpr
					mult(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs * scalar;
				}
			protected:
				Scalar scalar;
			};

			template<class Scalar>
			struct del
			{
				constexpr
					del(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs / scalar;
				}
			protected:
				Scalar scalar;
			};
			template<class Scalar>
			struct del1
			{
				constexpr
					del1(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return  scalar / ihs;
				}
			protected:
				Scalar scalar;
			};

			
			struct abs
			{
				template< class T  >	
				constexpr T operator()(const T& ihs)
				{
					return std::abs(ihs);
				}
			};


			
			struct sqrt
			{
				
				
				template< class T>
				constexpr T operator()(const T& ihs)
				{
					return std::sqrt(ihs);
				}
			};

		}
		namespace BinaryOps
		{
			template <class T = void>
			using plus = std::plus<T>;

			template <class T = void>
			using minus = std::minus<T>;

			template <class T = void>
			using multi = std::multiplies<T>;


			template <class T = void>
			using del = std::divides<T>;



		}
	}


	
	/*template <size_t dim>
	PointVal<dim> operator +(const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		return PointVal<dim>{p1.p + p2.p, p1.val + p2.val};
	};
	template < size_t dim>
	PointVal<dim> operator -(const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		return PointVal<dim>{p1.p - p2.p, p1.val - p2.val};
	};
	template <size_t dim>
	PointVal<dim> operator *(const PointVal<dim>& p1, const PointVal<dim>& p2)
	{
		return PointVal<dim>{p1.p* p2.p, p1.val* p2.val};
	};
	/*PointVal<dim> operator *(const PointVal<dim>& p1, double scalar)
	{
		return PointVal<dim>{p1* scalar, p1.val};
	};
	PointVal<dim> operator *( double scalar, const PointVal<dim>& p1)// со скаляром не работает
	{
		return p1* scalar;
	};
	PointVal<dim> operator +(const PointVal<dim>& p1, double scalar)
	{
		return PointVal<dim>{p1 + scalar, p1.val};
	};
	PointVal<dim> operator +(double scalar, const PointVal<dim>& p1)
	{
		return p1 + scalar;
	};
	PointVal<dim> operator -(const PointVal<dim>& p1, double scalar)
	{
		return PointVal<dim>{p1- scalar, p1.val};
	};
	PointVal<dim> operator -(double scalar, const PointVal<dim>& p1)
	{
		return PointVal<dim>{scalar-p1, p1.val};
	};*/
}
/*
+double val не добавляется
-
-double аналогично
p/double и точка и val
*double и точка и val
sqrt
abs

*/