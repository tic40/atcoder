javascript:(function() {
  if (new URL(window.location.href).host !== 'atcoder.jp') { alert('Error: only works on atcoder.jp'); return; }
  let num = 1;
  const messages = [];
  document.querySelectorAll("[id^='pre-sample']").forEach(v => {
    const prevTextContent = v.previousSibling.previousSibling.textContent;
    if (!RegExp('^入力例 [0-9]+').test(prevTextContent)) return;

    const blob = new Blob([v.textContent], { type: 'application/octet-stream' });
    const a = document.createElement('a');
    a.href = window.URL.createObjectURL(blob);
    const filename = `test${num++}`;
    a.download = filename;
    a.click();
    messages.push(`downloaded: ${filename}\n${v.textContent}`);
  });
  if (messages.length) console.info(messages.join('\n'));
  else alert('Error: no sample inputs');
})();