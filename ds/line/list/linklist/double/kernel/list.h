/*
 * @Author       : fieldxy
 * @Date         : 2020-05-01 18:10:28
 * @LastEditors  : fieldxy
 * @LastEditTime : 2020-05-01 19:35:49
 * @Description  : In User Settings Edit
 * @FilePath     : /apue/ds/line/list/linklist/double/kernel/list.h
 */
#ifndef LINUX_LIST_H
#define LINUX_LIST_H

struct list_head
{
    struct list_head * prev;
    struct list_head * next;

};

#define LIST_HEAD_INIT(name)    {&(name),&(name)}

#define LIST_HEAD(name)         struct list_head name = LIST_HEAD_INIT(name)



/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
{


	next->prev = new;
	new->next = next;
	new->prev = prev;
    prev->next = new;
	// WRITE_ONCE(prev->next, new);
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}



/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop cursor.
 * @head:	the head for your list.
 */
#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

#define offsetof(TYPE, MEMBER)	((size_t)&((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({				\
	void *__mptr = (void *)(ptr);					\
	((type *)(__mptr - offsetof(type, member))); })



/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 */
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)



#endif