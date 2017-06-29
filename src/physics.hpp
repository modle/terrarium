/*
 * physics.hpp
 *
 *  Created on: 28/10/2013
 *      Author: felipe
 */

#ifndef PHYSICS_HPP_
#define PHYSICS_HPP_

namespace Physics
{
	float convertToMeters(float pixels);
	float convertToPixels(float meters);

	//pre-declaring these classes to avoid annoying declaration order issues...
	class World;

	/** A simple 3D vector */
	struct Vector
	{
		float x, y, z;

		Vector();
		Vector(float x1=0, float y1=0, float z1=0);
		Vector(const Vector &v);
	};

	/** Represents a physical body. Note that most methods will crash if called when the body is detatched. */
	class Body
	{
		friend class World;

		struct Implementation;
		Implementation* implementation;

		public:

		struct Type
		{
			enum
			{
				BLOCK,  // blocks cannot be moved. blocks can be collided with or not.
				ACTOR,  // actors can be moved. actors can be collided with or not.
				DROP,   // drops can be moved. drops collide only with blocks.
				BULLET, // bullets can be moved. bullets collides with actors and blocks only. bullets are optimized for high speeds.
			};
		};

		/// General constructor. Everything must be passed in meters.
		Body(double x, double y, double width, double height, int type=Type::ACTOR, bool ignoreCollisions=false);

		~Body();

		// Detatched-safe methods (the following methods can be called when the body is detatched)

		/** Returns whether this body is already bound to a world instance. */
		bool isDetached();

		double getX() const;
		double getY() const;
		Vector getPosition() const;

		// Atatched-only methods (the following methods will crash if called when the body is detatched)

		double getWidth() const;
		double getHeight() const;
		Vector getVelocity() const;
		float getAngle() const;

		bool isRotationFixed() const;
		void setFixedRotation(bool choice=true);

		void applyImpulse(const Vector& impulse, const Vector& point);
		void applyForceToCenter(const Vector& force);
		void move(const Vector& displacement);
		void rotate(const double& angle);
		void transform(const Vector& displacement, const double& angle);
	};

	/** Represents the world */
	class World
	{
		struct Implementation;
		Implementation* implementation;

		public:

		World(Vector gravityAcceleration);
		~World();

		void addBody(Body* b);
		void destroyBody(Body* b);

		void step(float timeStep, int velocityIterations, int positionIterations);
	};
}


#endif /* PHYSICS_HPP_ */
