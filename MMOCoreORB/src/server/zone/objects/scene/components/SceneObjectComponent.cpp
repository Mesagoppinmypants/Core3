/*
 *	server/zone/objects/scene/components/SceneObjectComponent.cpp generated by engine3 IDL compiler 0.60
 */

#include "SceneObjectComponent.h"

#include "server/zone/objects/scene/SceneObject.h"

/*
 *	SceneObjectComponentStub
 */

enum {RPC_INITIALIZE__SCENEOBJECT_ = 6,RPC_GETSCENEOBJECT__,RPC_NOTIFYLOADFROMDATABASE__};

SceneObjectComponent::SceneObjectComponent() : ManagedObject(DummyConstructorParameter::instance()) {
	SceneObjectComponentImplementation* _implementation = new SceneObjectComponentImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

SceneObjectComponent::SceneObjectComponent(DummyConstructorParameter* param) : ManagedObject(param) {
}

SceneObjectComponent::~SceneObjectComponent() {
}


void SceneObjectComponent::initialize(SceneObject* obj) {
	SceneObjectComponentImplementation* _implementation = (SceneObjectComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZE__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->initialize(obj);
}

SceneObject* SceneObjectComponent::getSceneObject() {
	SceneObjectComponentImplementation* _implementation = (SceneObjectComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSCENEOBJECT__);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getSceneObject();
}

void SceneObjectComponent::notifyLoadFromDatabase() {
	SceneObjectComponentImplementation* _implementation = (SceneObjectComponentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYLOADFROMDATABASE__);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyLoadFromDatabase();
}

DistributedObjectServant* SceneObjectComponent::_getImplementation() {

	_updated = true;
	return _impl;
}

void SceneObjectComponent::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	SceneObjectComponentImplementation
 */

SceneObjectComponentImplementation::SceneObjectComponentImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


SceneObjectComponentImplementation::~SceneObjectComponentImplementation() {
}


void SceneObjectComponentImplementation::finalize() {
}

void SceneObjectComponentImplementation::_initializeImplementation() {
	_setClassHelper(SceneObjectComponentHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SceneObjectComponentImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SceneObjectComponent*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* SceneObjectComponentImplementation::_getStub() {
	return _this;
}

SceneObjectComponentImplementation::operator const SceneObjectComponent*() {
	return _this;
}

void SceneObjectComponentImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SceneObjectComponentImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SceneObjectComponentImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SceneObjectComponentImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SceneObjectComponentImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SceneObjectComponentImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SceneObjectComponentImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SceneObjectComponentImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("SceneObjectComponent");

}

void SceneObjectComponentImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SceneObjectComponentImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SceneObjectComponentImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "sceneObject") {
		TypeInfo<ManagedWeakReference<SceneObject* > >::parseFromBinaryStream(&sceneObject, stream);
		return true;
	}


	return false;
}

void SceneObjectComponentImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SceneObjectComponentImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SceneObjectComponentImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "sceneObject";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<SceneObject* > >::toBinaryStream(&sceneObject, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ManagedObjectImplementation::writeObjectMembers(stream);
}

SceneObjectComponentImplementation::SceneObjectComponentImplementation() : ManagedObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/scene/components/SceneObjectComponent.idl():  		sceneObject = null;
	sceneObject = NULL;
}

void SceneObjectComponentImplementation::initialize(SceneObject* obj) {
	// server/zone/objects/scene/components/SceneObjectComponent.idl():  		sceneObject = obj;
	sceneObject = obj;
}

SceneObject* SceneObjectComponentImplementation::getSceneObject() {
	// server/zone/objects/scene/components/SceneObjectComponent.idl():  		return sceneObject;
	return sceneObject;
}

void SceneObjectComponentImplementation::notifyLoadFromDatabase() {
}

/*
 *	SceneObjectComponentAdapter
 */

SceneObjectComponentAdapter::SceneObjectComponentAdapter(SceneObjectComponentImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* SceneObjectComponentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZE__SCENEOBJECT_:
		initialize((SceneObject*) inv->getObjectParameter());
		break;
	case RPC_GETSCENEOBJECT__:
		resp->insertLong(getSceneObject()->_getObjectID());
		break;
	case RPC_NOTIFYLOADFROMDATABASE__:
		notifyLoadFromDatabase();
		break;
	default:
		return NULL;
	}

	return resp;
}

void SceneObjectComponentAdapter::initialize(SceneObject* obj) {
	((SceneObjectComponentImplementation*) impl)->initialize(obj);
}

SceneObject* SceneObjectComponentAdapter::getSceneObject() {
	return ((SceneObjectComponentImplementation*) impl)->getSceneObject();
}

void SceneObjectComponentAdapter::notifyLoadFromDatabase() {
	((SceneObjectComponentImplementation*) impl)->notifyLoadFromDatabase();
}

/*
 *	SceneObjectComponentHelper
 */

SceneObjectComponentHelper* SceneObjectComponentHelper::staticInitializer = SceneObjectComponentHelper::instance();

SceneObjectComponentHelper::SceneObjectComponentHelper() {
	className = "SceneObjectComponent";

	Core::getObjectBroker()->registerClass(className, this);
}

void SceneObjectComponentHelper::finalizeHelper() {
	SceneObjectComponentHelper::finalize();
}

DistributedObject* SceneObjectComponentHelper::instantiateObject() {
	return new SceneObjectComponent(DummyConstructorParameter::instance());
}

DistributedObjectServant* SceneObjectComponentHelper::instantiateServant() {
	return new SceneObjectComponentImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SceneObjectComponentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SceneObjectComponentAdapter((SceneObjectComponentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

