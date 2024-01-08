//SPDX-License-Identifier: Unlicense


pragma solidity ^0.8.0;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

contract RunToken is ERC20 {
        constructor() ERC20("DamnToken", "DAMN")
        {
            _mint(msg.sender, 20 * 10 ** 6);
        }
        function mintTokens(address account, uint256 amount) public
        {
            _mint(account, amount); 
        }
}