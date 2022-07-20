#pragma once

#ifndef NOVACONSTRUCTOR_H
#define NOVACONSTRUCTOR_H

#define SINGLETONCONSTRUCTOR(ClassName) \
	protected: ClassName(); public:\
	ClassName(const ClassName &) = delete; \
	ClassName(ClassName &&) = delete; \
	ClassName & operator = (const ClassName &) = delete; \
	ClassName & operator = (ClassName &&) = delete;

#define DEFAULTSINGLETONCONSTRUCTOR(ClassName) \
	protected: ClassName() = default; public:\
	ClassName(const ClassName &) = delete; \
	ClassName(ClassName &&) = delete; \
	ClassName & operator = (const ClassName &) = delete; \
	ClassName & operator = (ClassName &&) = delete;

#define CONSTRUCTOR(ClassName) \
	ClassName(); \
	ClassName(const ClassName &) = delete; \
	ClassName(ClassName &&) = delete; \
	ClassName & operator = (const ClassName &) = delete; \
	ClassName & operator = (ClassName &&) = delete;

#define DEFAULTCONSTRUCTOR(ClassName) \
	ClassName() = default; \
	ClassName(const ClassName &) = delete; \
	ClassName(ClassName &&) = delete; \
	ClassName & operator = (const ClassName &) = delete; \
	ClassName & operator = (ClassName &&) = delete; \
	size_t Size() { return sizeof(*this);}

#define DELETECONSTRUCTOR(ClassName) \
	ClassName() = delete; \
	ClassName(const ClassName &) = delete; \
	ClassName(ClassName &&) = delete; \
	ClassName & operator = (const ClassName &) = delete; \
	ClassName & operator = (ClassName &&) = default;

#define DESTRUCTOR(ClassName) \
	virtual ~ClassName();

#define DEFAULTDESTRUCTOR(ClassName) \
	virtual ~ClassName() = default;

#define DELETEDESTRUCTOR(ClassName) \
	virtual ~ClassName() = delete;

#define RETURNEMPTYWEAKPTR(ClassName) { \
	weak_ptr<ClassName> _weak_ptr; \
	_weak_ptr.reset(); \
	return _weak_ptr; }

#endif // !NOVACONSTRUCTOR_H