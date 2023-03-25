#include <Account.h>

#include <gtest/gtest.h>

TEST(Account, Balance) {	
	Account account(1234567, 100);
	EXPECT_EQ(account.GetBalance(), 100);
	account.Lock();
	account.ChangeBalance(50);
	account.Unlock();
	EXPECT_EQ(account.GetBalance(), 150);
}

TEST(Account, Locking) {
	Account account(7654321, 200);
	EXPECT_THROW(account.ChangeBalance(50), std::runtime_error);
	account.Lock();
	EXPECT_THROW(account.Lock(), std::runtime_error);
	EXPECT_NO_THROW(account.ChangeBalance(49));
	EXPECT_EQ(account.GetBalance(), 249);	
}
