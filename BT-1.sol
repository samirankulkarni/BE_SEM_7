//SPDX-License-Identifier:UNLICENSED
pragma solidity ^0.8.0;

contract Bank_1{

    uint16 balance = 0;
    address public account;

    constructor(){
        account = msg.sender;
    }


    function checkBalance() public view returns (uint16){
        return balance;
    }

    function deposit(uint16 amt) public payable {
        require(amt > 0,"you cant deposit 0");
        balance += amt;
    }

    function withdraw(uint16 amt) public payable {
        require(balance >= amt,"balace is not enough");
        balance -= amt;
    }
}