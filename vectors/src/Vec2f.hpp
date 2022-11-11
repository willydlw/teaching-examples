#ifndef VEC2F_HPP
#define VEC2F_HPP

class Vec2f
{
   public:
      Vec2f();
      Vec2f(float x, float y);


      // getter functions
      float getX() const;
      float getY() const;

      // setter functions
      void setX(float x);
      void setY(float y);
      
      // overloaded operators
      Vec2f operator + (const Vec2f& rhs) const;
      Vec2f operator - (const Vec2f& rhs) const;
       
   private:

      float m_x = 0.0;
      float m_y = 0.0;
};

#endif 