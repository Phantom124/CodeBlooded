/**
 * @file CustomerCommand.h
 * @brief Command wrapper for operations that act on a Customer.
 *
 * This header defines the CustomerCommand class which is a concrete
 * specialization of the generic `Command` interface. Instances of
 * `CustomerCommand` encapsulate an operation type and a pointer to a
 * `Customer` object so the command can be executed against that
 * customer (for example: place order, modify account, generate
 * receipt, etc.).
 *
 * @author Jared Williams
 * @date 2025-11-04
 */

#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include <string>
#include "Command.h"
#include "Customer.h"

class CustomerCommand : public Command {

protected:
	std::string type;
	Customer* customer;

public:
	/**
	 * @brief Construct a new CustomerCommand.
	 *
	 * @param type The command type (see `cmdType` in `Command.h`) that
	 *             indicates which action this command represents.
	 * @param customer Pointer to the `Customer` instance this command
	 *                 will operate on. Ownership is not transferred; the
	 *                 caller is responsible for the lifetime of the
	 *                 `Customer` object.
	 */
	CustomerCommand(const cmdType type, Customer* customer);

	/**
	 * @brief Virtual destructor.
	 *
	 * Ensures derived command objects are properly destroyed through a
	 * `Command*` pointer. No special cleanup is required by
	 * `CustomerCommand` itself.
	 */
	virtual ~CustomerCommand();
};

#endif
