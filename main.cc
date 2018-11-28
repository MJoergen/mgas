#include <iostream>
#include <vector>

// This structure contains the size of the universe
struct Universe
{
   Universe(double width, double height) : m_width(width), m_height(height) {}
   double m_width;
   double m_height;
}; // end of struct Universe


// This class contains the position etc of a single gas particle
class Particle
{
   public:
      Particle(double radius,
               double mass,
               double pos_x,
               double pos_y,
               double vel_x,
               double vel_y, 
               struct Universe *pUniverse) :
         m_radius(radius),
         m_mass(mass),
         m_pos_x(pos_x),
         m_pos_y(pos_y),
         m_vel_x(vel_x),
         m_vel_y(vel_y),
         m_pUniverse(pUniverse)
         {}

      void update();
      void collision(Particle *other);

   private:
      double m_radius;
      double m_mass;
      double m_pos_x;
      double m_pos_y;
      double m_vel_x;
      double m_vel_y;
      struct Universe *m_pUniverse;
}; // end of class Particle


// This function moves a single gas particle a fixed time step.
void Particle::update()
{
   m_pos_x += m_vel_x;
   m_pos_y += m_vel_y;

   // TODO: Check for collision with universe boundary.
} // end of void Particle::update()


// This function checks if there is a collision with the other
// particle, and if so updates both their velocities.
void Particle::collision(Particle *other)
{
   // TODO:
} // end of void Particle::collision(Particle *other)

int main()
{
   Universe universe(800, 600);
   std::vector<Particle *> particles;
   particles.push_back(new Particle(
            10,                  // radius
            1,                   // mass
            700*rand()+50,       // pos_x
            500*rand()+50,       // pos_y
            0.2*rand()-0.1,      // vel_x
            0.2*rand()-0.1,      // vel_y
            &universe));

   // This is the main loop, that iterates over each time step
   while (true)
   {
      // Loop over all particles and update their position
      for (auto it : particles)
      {
         it->update();
      }

      // Check for collision
      for (auto first = particles.begin(); first != particles.end(); first++)
      {
         for (auto second = first+1; second != particles.end(); second++)
         {
            (*first)->collision(*second);
         }
      }
   }
   return 0;
} // end of int main()

