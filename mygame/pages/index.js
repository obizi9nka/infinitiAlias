import Head from 'next/head'
import Image from 'next/image'
import { Inter } from '@next/font/google'
import styles from '@/styles/Home.module.css'

import jsonMas from "../russian_nouns_with_definition_ready.json"
import { useEffect, useState } from 'react'

export default function Home() {



  function random() {
    let rand = 0 - 0.5 + Math.random() * (26477 - 0 + 1);
    return Math.round(rand);
  }

  const [index, setindex] = useState(random())

  const [name, setname] = useState("")
  const [description, setdescription] = useState("")

  const next = () => {
    setindex(random())
  }

  useEffect(() => {
    setname(jsonMas[index].name.toUpperCase())
    setdescription(jsonMas[index].description)
  }, [index])


  return (
    <div>
      <div className='name'>
        {name}
      </div>
      <div className='description'>
        {description}
      </div>
      <div className='buttonArea'>
        <button onClick={next} className='button'>
          Следующее слово
        </button>
      </div>

    </div>
  )
}
