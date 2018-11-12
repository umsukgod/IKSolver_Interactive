#ifndef BODYNODE_H
#define BODYNODE_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
#include <Eigen/Dense>
typedef struct Box_ 
{
	float width;
	float height;
	float depth;
} Box;

typedef struct Joint_
{
	Eigen::Isometry3d parentBodyToJoint;
	Eigen::Isometry3d childBodyToJoint;
} Joint;

class BodyNode
{
public:
	BodyNode(std::string name, std::shared_ptr<BodyNode> parentNode);
	BodyNode(std::string name);
	void setTransform(Eigen::Isometry3d transform_)	{transform = transform_;}
	void setWorldTranslation(Eigen::Vector3d translation);
	void setWorldRotation(Eigen::Matrix3d rotation);
	void setRotation(Eigen::Matrix3d rotation);
	void Translate(Eigen::Vector3d translation);
	Eigen::Isometry3d getTransform();
	Eigen::Isometry3d getWorldTransform()			{return worldTransform;}
	bool haveParent()								{return haveParent_;}
	std::shared_ptr<BodyNode> getParent()			{return parentNode;}
	std::string getName()							{return name;}
	void setShape(float width, float height, float depth);
	Box getShape()									{return boxShape;}
	Joint getJoint()								{return joint;}
	void setJoint(Eigen::Isometry3d pbtj, Eigen::Isometry3d cbtj);
	void updateWorldTransform();
private:
	std::string name;
	std::shared_ptr<BodyNode> parentNode;
	Eigen::Isometry3d worldTransform;
	Eigen::Isometry3d transform;
	Joint joint;

	bool haveParent_;
	Box boxShape;
};
typedef std::shared_ptr<BodyNode> BodyNodePtr;


#endif	//BODYNODE_H

