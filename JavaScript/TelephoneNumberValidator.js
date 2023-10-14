function telephoneCheck(str) {
  let phoneFilter = /^(1 )?[\S ]?(\d{3}|\(\d{3}\))[\- ]?\d{3}[\- ]?\d{4}$/ 

  let regex = /^([1]\s?)?(\([0-9]{3}\)|[0-9]{3})(\s|-)?[0-9]{3}(\s|-)?[0-9]{4}$/g

  

  let strFilter = str.replace(/[^0-9]/g, '')
  console.log(strFilter)

   if(strFilter.length === 10 && 
      str.match(regex)) {
     console.log('true')
    return true
  } else if(strFilter.length === 11 && 
            strFilter.slice(0,1) === '1' &&
            str.match(regex)) {
    console.log('true')

    return true
  } else {
    console.log('false')
    return false
  }
  
}

//should be true
telephoneCheck("1(555)555-5555") //true
telephoneCheck("(555-555-5555") //false