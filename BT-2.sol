//SPDX-License-Identifier:UNLICENSED
pragma solidity ^0.8.0;

contract Student_1{

    struct Student{
        uint16 id;
        string name;
    }

    Student[] public studentData;

    function addStudent(string memory name,uint16 id) public{
        for(uint8 i=0;i<studentData.length;i++){
            if(studentData[i].id == id){
                revert("id already exists");
            }
        }
        studentData.push(Student(id,name));
    }

    function getAll() public view returns (Student[] memory){
        require(studentData.length > 0,"studentdata is empty");
        return studentData;
    }

    function getLength() public view returns (uint256){
        return studentData.length;
    }

    function getIndex(uint16 idx) public view returns (Student memory){
        require(idx < studentData.length,"index out of bound");
        return studentData[idx];
    }

}