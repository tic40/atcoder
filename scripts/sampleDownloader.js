const fs = require('fs')
const http = require('http')
const https = require('https')

const url = process.argv[2]
if (!url) return console.error('Argument Error: Please specify url.')

const client = url.startsWith('https') ? https : http
const re1 = RegExp('<h3>入力例 [0-9]+')
const re2 = RegExp('<pre>([\\S\\s]*?)<\/pre>')

const request = client.get(url, res => {
  res.on('data', d => {
    const content = d.toString()
    content.split(re1).forEach((chunk, i) => {
      if (i === 0) return
      const sample = chunk.match(re2)[1]
      fs.writeFileSync(`test${i}`, sample)
      console.log(`[created test${i}]`)
      console.log(sample)
    })
  })
})
request.on('error', err => console.error('error occurred while downloading.', err))
